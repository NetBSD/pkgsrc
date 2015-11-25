package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"sort"
	"strings"
)

var files map[string][]string
var filenames []string

func readPlist(fname string) {
	lines, err := ioutil.ReadFile(fname)
	if err != nil {
		fmt.Fprintf(os.Stderr, "warning: %s\n", err)
		return
	}

	for lineno, line := range strings.Split(string(lines), "\n") {
		if !strings.HasPrefix(line, "@") {
			if files[line] == nil {
				filenames = append(filenames, line)
			}
			files[line] = append(files[line], fmt.Sprintf("%s:%d", fname, lineno+1))
		}
	}
}

func main() {
	if len(os.Args) == 1 {
		fmt.Fprintf(os.Stderr, "usage: %s <plist>...", os.Args[0])
	}

	for _, plist := range os.Args[1:] {
		readPlist(plist)
	}

	sort.Strings(filenames)

	for _, filename := range filenames {
		sources := files[filename]
		if len(sources) != 1 {
			for _, source := range sources {
				fmt.Printf("%s: %s\n", source, filename)
			}
		}
	}
}
