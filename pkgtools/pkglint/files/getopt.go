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
	options []*Option
}

func NewOptions() *Options {
	return new(Options)
}

func (self *Options) AddFlagGroup(shortName rune, longName, argDescription, description string) *FlagGroup {
	grp := new(FlagGroup)
	opt := &Option{shortName, longName, argDescription, description, grp}
	self.options = append(self.options, opt)
	return grp
}

func (self *Options) AddFlagVar(shortName rune, longName string, pflag *bool, defval bool, description string) {
	*pflag = defval
	opt := &Option{shortName, longName, "", description, pflag}
	self.options = append(self.options, opt)
}

func (self *Options) Parse(args []string) (remainingArgs []string, err error) {
	defer func() {
		if r := recover(); r != nil {
			if rerr, ok := r.(OptErr); ok {
				err = OptErr(args[0] + ": " + string(rerr))
			} else {
				panic(r)
			}
		}
	}()

	for i := 1; i < len(args); i++ {
		arg := args[i]
		switch {
		case arg == "--":
			return append(remainingArgs, args[i+1:]...), nil
		case hasPrefix(arg, "--"):
			i += self.parseLongOption(args, i, arg[2:])
		case hasPrefix(arg, "-"):
			i += self.parseShortOptions(args, i, arg[1:])
		default:
			remainingArgs = append(remainingArgs, arg)
		}
	}
	return
}

func (self *Options) parseLongOption(args []string, i int, argRest string) int {
	parts := strings.SplitN(argRest, "=", 2)
	argname := parts[0]
	var argval *string
	if 1 < len(parts) {
		argval = &parts[1]
	}

	for _, opt := range self.options {
		if argname == opt.longName {
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
						panic(OptErr("invalid argument for option --" + opt.longName))
					}
				}
				return 0
			case *FlagGroup:
				if argval == nil {
					data.parse("--"+opt.longName+"=", args[i+1])
					return 1
				} else {
					data.parse("--"+opt.longName+"=", *argval)
					return 0
				}
			}
		}
	}
	panic(OptErr("unknown option: --" + argRest))
}

func (self *Options) parseShortOptions(args []string, i int, optchars string) int {
optchar:
	for ai, optchar := range optchars {
		for _, opt := range self.options {
			if optchar == opt.shortName {
				switch data := opt.data.(type) {
				case *bool:
					*data = true
					continue optchar
				case *FlagGroup:
					argarg := optchars[ai+utf8.RuneLen(optchar):]
					if argarg != "" {
						data.parse(sprintf("-%c", optchar), argarg)
						return 0
					} else {
						data.parse(sprintf("-%c", optchar), args[i+1])
						return 1
					}
				}
			}
		}
		panic(OptErr(sprintf("unknown option: -%c", optchar)))
	}
	return 0
}

func (self *Options) Help(out io.Writer, generalUsage string) {
	wr := tabwriter.NewWriter(out, 1, 0, 2, ' ', tabwriter.TabIndent)

	fmt.Fprintf(wr, "usage: %s\n", generalUsage)
	fmt.Fprintln(wr)
	wr.Flush()

	for _, opt := range self.options {
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
	for _, opt := range self.options {
		switch flagGroup := opt.data.(type) {
		case *FlagGroup:
			hasFlagGroups = true
			fmt.Fprintln(wr)
			fmt.Fprintf(wr, "  Flags for -%c, --%s:\n", opt.shortName, opt.longName)
			fmt.Fprintf(wr, "    all\t all of the following\n")
			fmt.Fprintf(wr, "    none\t none of the following\n")
			for _, flag := range flagGroup.flags {
				fmt.Fprintf(wr, "    %s\t %s (%v)\n", flag.name, flag.help, ifelseStr(*flag.value, "enabled", "disabled"))
			}
			wr.Flush()
		}
	}
	if hasFlagGroups {
		fmt.Fprintln(wr)
		fmt.Fprint(wr, "  (Prefix a flag with \"no-\" to disable it.)\n")
		wr.Flush()
	}
}

type Option struct {
	shortName      rune
	longName       string
	argDescription string
	description    string
	data           interface{}
}

type FlagGroup struct {
	flags []*GroupFlag
}

func (self *FlagGroup) AddFlagVar(name string, flag *bool, defval bool, help string) {
	opt := &GroupFlag{name, flag, help}
	self.flags = append(self.flags, opt)
	*flag = defval
}

func (self *FlagGroup) parse(optionPrefix, arg string) {
argopt:
	for _, argopt := range strings.Split(arg, ",") {
		if argopt == "none" || argopt == "all" {
			for _, opt := range self.flags {
				*opt.value = argopt == "all"
			}
			continue argopt
		}
		for _, opt := range self.flags {
			if argopt == opt.name {
				*opt.value = true
				continue argopt
			}
			if argopt == "no-"+opt.name {
				*opt.value = false
				continue argopt
			}
		}
		panic(OptErr("unknown option: " + optionPrefix + argopt))
	}
}

type GroupFlag struct {
	name  string
	value *bool
	help  string
}

type OptErr string

func (err OptErr) Error() string {
	return string(err)
}
