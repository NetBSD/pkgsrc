package main

import (
	"netbsd.org/pkglint"
	"os"
)

var exit = os.Exit

func main() {
	exit(pkglint.Main())
}
