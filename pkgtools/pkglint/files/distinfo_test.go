package main

import (
	check "gopkg.in/check.v1"
	"io/ioutil"
	"os"
	"path/filepath"
)

func (s *Suite) TestChecklinesDistinfo(c *check.C) {
	tmpdir := c.MkDir()
	patchesdir := tmpdir + "/patches"
	patchAa := patchesdir + "/patch-aa"
	patchContents := "" +
		"$" + "NetBSD$ line is ignored\n" +
		"patch contents\n"

	os.Mkdir(patchesdir, 0777)
	if err := ioutil.WriteFile(patchAa, []byte(patchContents), 0666); err != nil {
		c.Fatal(err)
	}
	G.currentDir = filepath.ToSlash(tmpdir)

	lines := s.NewLines("distinfo",
		"should be the RCS ID",
		"should be empty",
		"MD5 (distfile.tar.gz) = 12345678901234567890123456789012",
		"SHA1 (distfile.tar.gz) = 1234567890123456789012345678901234567890",
		"SHA1 (patch-aa) = 6b98dd609f85a9eb9c4c1e4e7055a6aaa62b7cc7")

	checklinesDistinfo(lines)

	c.Check(s.Output(), equals, ""+
		"ERROR: distinfo:1: Expected \"$NetBSD: distinfo_test.go,v 1.1 2015/11/25 13:29:07 rillig Exp $\".\n"+
		"NOTE: distinfo:2: Empty line expected.\n"+
		"ERROR: distinfo:5: Expected SHA1, RMD160, SHA512, Size checksums for \"distfile.tar.gz\", got MD5, SHA1.\n")
}
