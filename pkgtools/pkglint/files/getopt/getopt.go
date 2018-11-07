// Package getopt provides a parser for command line options,
// supporting multi-value options such as -Wall,no-extra.
package getopt

import (
	"errors"
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

// AddFlagGroup adds an option that takes multiple flag values.
//
// Example:
//  var extra bool
//
//  opts := NewOptions()
//  warnings := opts.AddFlagGroup('W', "warnings", "warning,...", "Enable the given warnings")
//  warnings.AddFlagVar("extra", &extra, false, "Print extra warnings")
func (o *Options) AddFlagGroup(shortName rune, longName, argsName, description string) *FlagGroup {
	grp := new(FlagGroup)
	opt := &option{shortName, longName, argsName, description, grp}
	o.options = append(o.options, opt)
	return grp
}

func (o *Options) AddFlagVar(shortName rune, longName string, pflag *bool, defval bool, description string) {
	*pflag = defval
	opt := &option{shortName, longName, "", description, pflag}
	o.options = append(o.options, opt)
}

func (o *Options) AddStrList(shortName rune, longName string, plist *[]string, description string) {
	*plist = []string{}
	opt := &option{shortName, longName, "", description, plist}
	o.options = append(o.options, opt)
}

// Parse extracts the command line options from the given arguments.
// args[0] is the program name, as in os.Args.
func (o *Options) Parse(args []string) (remainingArgs []string, err error) {
	var skip int
	for i := 1; i < len(args) && err == nil; i++ {
		arg := args[i]
		switch {
		case arg == "--":
			remainingArgs = append(remainingArgs, args[i+1:]...)
			return
		case strings.HasPrefix(arg, "--"):
			skip, err = o.parseLongOption(args, i, arg[2:])
			i += skip
		case strings.HasPrefix(arg, "-"):
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
			case "true", "on", "enabled", "1", "yes":
				*data = true
			case "false", "off", "disabled", "0", "no":
				*data = false
			default:
				return 0, optErr("invalid argument for option --" + opt.longName)
			}
		}
		return 0, nil
	case *[]string:
		switch {
		case argval != nil:
			*data = append(*data, *argval)
			return 0, nil
		case i+1 < len(args):
			*data = append(*data, args[i+1])
			return 1, nil
		default:
			return 0, optErr("option requires an argument: --" + opt.longName)
		}
	case *FlagGroup:
		switch {
		case argval != nil:
			return 0, data.parse("--"+opt.longName+"=", *argval)
		case i+1 < len(args):
			return 1, data.parse("--"+opt.longName+"=", args[i+1])
		default:
			return 0, optErr("option requires an argument: --" + opt.longName)
		}
	}
	panic("getopt: internal error: unknown option type")
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

				case *[]string:
					argarg := optchars[ai+utf8.RuneLen(optchar):]
					switch {
					case argarg != "":
						*data = append(*data, argarg)
						return 0, nil
					case i+1 < len(args):
						*data = append(*data, args[i+1])
						return 1, nil
					default:
						return 0, optErr("option requires an argument: -" + string([]rune{optchar}))
					}

				case *FlagGroup:
					argarg := optchars[ai+utf8.RuneLen(optchar):]
					switch {
					case argarg != "":
						return 0, data.parse(string([]rune{'-', optchar}), argarg)
					case i+1 < len(args):
						return 1, data.parse(string([]rune{'-', optchar}), args[i+1])
					default:
						return 0, optErr("option requires an argument: -" + string([]rune{optchar}))
					}
				}
			}
		}
		return 0, optErr("unknown option: -" + string([]rune{optchar}))
	}
	return 0, nil
}

// Help writes a summary of the options to the given writer,
// in tabular format.
func (o *Options) Help(out io.Writer, generalUsage string) {
	wr := tabwriter.NewWriter(out, 1, 0, 2, ' ', tabwriter.TabIndent)

	rowf := func(format string, args ...interface{}) {
		_, _ = fmt.Fprintf(wr, format, args...)
		_, _ = io.WriteString(wr, "\n")
	}
	finishTable := func() { _ = wr.Flush() }

	rowf("usage: %s", generalUsage)
	rowf("")
	finishTable()

	for _, opt := range o.options {
		if opt.argsName == "" {
			rowf("  -%c, --%s\t %s",
				opt.shortName, opt.longName, opt.description)
		} else {
			rowf("  -%c, --%s=%s\t %s",
				opt.shortName, opt.longName, opt.argsName, opt.description)
		}
	}
	finishTable()

	hasFlagGroups := false
	for _, opt := range o.options {
		switch flagGroup := opt.data.(type) {
		case *FlagGroup:
			hasFlagGroups = true
			rowf("")
			rowf("  Flags for -%c, --%s:", opt.shortName, opt.longName)
			rowf("    all\t all of the following")
			rowf("    none\t none of the following")
			for _, flag := range flagGroup.flags {
				state := "disabled"
				if *flag.value {
					state = "enabled"
				}
				rowf("    %s\t %s (%v)", flag.name, flag.description, state)
			}
			finishTable()
		}
	}
	if hasFlagGroups {
		rowf("")
		rowf("  (Prefix a flag with \"no-\" to disable it.)")
		finishTable()
	}
}

type option struct {
	shortName   rune
	longName    string
	argsName    string
	description string
	data        interface{}
}

type FlagGroup struct {
	flags []*groupFlag
}

type groupFlag struct {
	name        string
	value       *bool
	description string
}

func (fg *FlagGroup) AddFlagVar(name string, flag *bool, defval bool, description string) {
	opt := &groupFlag{name, flag, description}
	fg.flags = append(fg.flags, opt)
	*flag = defval
}

func (fg *FlagGroup) parse(optionPrefix, arg string) error {
	for _, argOpt := range strings.Split(arg, ",") {
		err := fg.parseOpt(optionPrefix, argOpt)
		if err != nil {
			return err
		}
	}
	return nil
}

func (fg *FlagGroup) parseOpt(optionPrefix, argOpt string) error {

	if argOpt == "none" || argOpt == "all" {
		for _, opt := range fg.flags {
			*opt.value = argOpt == "all"
		}
		return nil
	}

	for _, opt := range fg.flags {
		if argOpt == opt.name {
			*opt.value = true
			return nil
		}
		if argOpt == "no-"+opt.name {
			*opt.value = false
			return nil
		}
	}

	return optErr("unknown option: " + optionPrefix + argOpt)
}

func optErr(str string) error { return errors.New(str) }
