package main

// Self-written getopt to support multi-argument options.

import (
	"fmt"
	"io"
	"strings"
	"text/tabwriter"
	"unicode/utf8"
)

type Options struct {
	options []*option
}

func NewOptions() *Options {
	return new(Options)
}

func (o *Options) AddFlagGroup(shortName rune, longName, argDescription, description string) *FlagGroup {
	switch { // prevent inlining
	}
	grp := new(FlagGroup)
	opt := &option{shortName, longName, argDescription, description, grp}
	o.options = append(o.options, opt)
	return grp
}

func (o *Options) AddFlagVar(shortName rune, longName string, pflag *bool, defval bool, description string) {
	switch { // prevent inlining
	}
	*pflag = defval
	opt := &option{shortName, longName, "", description, pflag}
	o.options = append(o.options, opt)
}

func (o *Options) Parse(args []string) (remainingArgs []string, err error) {
	var skip int
	for i := 1; i < len(args) && err == nil; i++ {
		arg := args[i]
		switch {
		case arg == "--":
			remainingArgs = append(remainingArgs, args[i+1:]...)
			return
		case hasPrefix(arg, "--"):
			skip, err = o.parseLongOption(args, i, arg[2:])
			i += skip
		case hasPrefix(arg, "-"):
			skip, err = o.parseShortOptions(args, i, arg[1:])
			i += skip
		default:
			remainingArgs = append(remainingArgs, arg)
		}
	}
	if err != nil {
		err = optErr(args[0] + ": " + err.Error())
	}
	return
}

func (o *Options) parseLongOption(args []string, i int, argRest string) (skip int, err error) {
	parts := strings.SplitN(argRest, "=", 2)
	argname := parts[0]
	var argval *string
	if 1 < len(parts) {
		argval = &parts[1]
	}

	for _, opt := range o.options {
		if argname == opt.longName {
			return o.handleLongOption(args, i, opt, argval)
		}
	}

	var prefixOpt *option
	for _, opt := range o.options {
		if strings.HasPrefix(opt.longName, argname) {
			if prefixOpt == nil {
				prefixOpt = opt
			} else {
				return 0, optErr(fmt.Sprintf("ambiguous option: --%s could mean --%s or --%s", argRest, prefixOpt.longName, opt.longName))
			}
		}
	}
	if prefixOpt != nil {
		return o.handleLongOption(args, i, prefixOpt, argval)
	}
	return 0, optErr("unknown option: --" + argRest)
}

func (o *Options) handleLongOption(args []string, i int, opt *option, argval *string) (skip int, err error) {
	switch data := opt.data.(type) {
	case *bool:
		if argval == nil {
			*data = true
		} else {
			switch *argval {
			case "true", "on", "enabled", "1":
				*data = true
			case "false", "off", "disabled", "0":
				*data = false
			default:
				return 0, optErr("invalid argument for option --" + opt.longName)
			}
		}
		return 0, nil
	case *FlagGroup:
		if argval == nil {
			return 1, data.parse("--"+opt.longName+"=", args[i+1])
		} else {
			return 0, data.parse("--"+opt.longName+"=", *argval)
		}
	}
	panic("getopt: unknown option type")
}

func (o *Options) parseShortOptions(args []string, i int, optchars string) (skip int, err error) {
optchar:
	for ai, optchar := range optchars {
		for _, opt := range o.options {
			if optchar == opt.shortName {
				switch data := opt.data.(type) {
				case *bool:
					*data = true
					continue optchar
				case *FlagGroup:
					argarg := optchars[ai+utf8.RuneLen(optchar):]
					if argarg != "" {
						return 0, data.parse(string([]rune{'-', optchar}), argarg)
					} else {
						return 1, data.parse(string([]rune{'-', optchar}), args[i+1])
					}
				}
			}
		}
		return 0, optErr("unknown option: -" + string([]rune{optchar}))
	}
	return 0, nil
}

func (o *Options) Help(out io.Writer, generalUsage string) {
	wr := tabwriter.NewWriter(out, 1, 0, 2, ' ', tabwriter.TabIndent)

	io.WriteString(wr, "usage: "+generalUsage+"\n")
	io.WriteString(wr, "\n")
	wr.Flush()

	for _, opt := range o.options {
		if opt.argDescription == "" {
			fmt.Fprintf(wr, "  -%c, --%s\t %s\n",
				opt.shortName, opt.longName, opt.description)
		} else {
			fmt.Fprintf(wr, "  -%c, --%s=%s\t %s\n",
				opt.shortName, opt.longName, opt.argDescription, opt.description)
		}
	}
	wr.Flush()

	hasFlagGroups := false
	for _, opt := range o.options {
		switch flagGroup := opt.data.(type) {
		case *FlagGroup:
			hasFlagGroups = true
			io.WriteString(wr, "\n")
			fmt.Fprintf(wr, "  Flags for -%c, --%s:\n", opt.shortName, opt.longName)
			io.WriteString(wr, "    all\t all of the following\n")
			io.WriteString(wr, "    none\t none of the following\n")
			for _, flag := range flagGroup.flags {
				fmt.Fprintf(wr, "    %s\t %s (%v)\n", flag.name, flag.help, ifelseStr(*flag.value, "enabled", "disabled"))
			}
			wr.Flush()
		}
	}
	if hasFlagGroups {
		io.WriteString(wr, "\n")
		io.WriteString(wr, "  (Prefix a flag with \"no-\" to disable it.)\n")
		wr.Flush()
	}
}

type option struct {
	shortName      rune
	longName       string
	argDescription string
	description    string
	data           interface{}
}

type FlagGroup struct {
	flags []*groupFlag
}

func (fg *FlagGroup) AddFlagVar(name string, flag *bool, defval bool, help string) {
	switch { // prevent inlining
	}
	opt := &groupFlag{name, flag, help}
	fg.flags = append(fg.flags, opt)
	*flag = defval
}

func (fg *FlagGroup) parse(optionPrefix, arg string) (err error) {
argopt:
	for _, argopt := range strings.Split(arg, ",") {
		if argopt == "none" || argopt == "all" {
			for _, opt := range fg.flags {
				*opt.value = argopt == "all"
			}
			continue argopt
		}
		for _, opt := range fg.flags {
			if argopt == opt.name {
				*opt.value = true
				continue argopt
			}
			if argopt == "no-"+opt.name {
				*opt.value = false
				continue argopt
			}
		}
		return optErr("unknown option: " + optionPrefix + argopt)
	}
	return nil
}

type groupFlag struct {
	name  string
	value *bool
	help  string
}

type optErr string

func (err optErr) Error() string {
	return string(err)
}
