package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestVartypeCheck_Category(c *check.C) {
	newVartypeCheck("CATEGORIES", "=", "chinese").Category()
	newVartypeCheck("CATEGORIES", "=", "arabic").Category()

	c.Check(s.Output(), equals, "ERROR: fname:1: Invalid category \"arabic\".\n")
}

func (s *Suite) TestVartypeCheck_Dependency(c *check.C) {
	newVartypeCheck("CONFLICTS", "+=", "Perl").Dependency()

	c.Check(s.Output(), equals, "WARN: fname:1: Unknown dependency format: Perl\n")

	newVartypeCheck("CONFLICTS", "+=", "perl5>=5.22").Dependency()

	c.Check(s.Output(), equals, "")

	newVartypeCheck("CONFLICTS", "+=", "perl5-*").Dependency()

	c.Check(s.Output(), equals, "WARN: fname:1: Please use \"perl5-[0-9]*\" instead of \"perl5-*\".\n")

	newVartypeCheck("CONFLICTS", "+=", "perl5-5.22.*").Dependency()

	c.Check(s.Output(), equals, "WARN: fname:1: Please append \"{,nb*}\" to the version number of this dependency.\n")

	newVartypeCheck("CONFLICTS", "+=", "perl5-5.22.*{,nb*}").Dependency()

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestVartypeCheck_DependencyWithPatch(c *check.C) {
	G.curPkgsrcdir = "../.."

	newVartypeCheck("DEPENDS", "+=", "Perl").DependencyWithPath()

	c.Check(s.Output(), equals, "WARN: fname:1: Unknown dependency format.\n")

	newVartypeCheck("DEPENDS", "+=", "perl5>=5.22:../perl5").DependencyWithPath()

	c.Check(s.Output(), equals, "WARN: fname:1: Dependencies should have the form \"../../category/package\".\n")

	newVartypeCheck("DEPENDS", "+=", "perl5>=5.24:../../lang/perl5").DependencyWithPath()

	c.Check(s.Output(), equals, ""+
		"ERROR: fname:1: \"../../lang/perl5\" does not exist.\n"+
		"ERROR: fname:1: There is no package in \"lang/perl5\".\n"+
		"WARN: fname:1: Please use USE_TOOLS+=perl:run instead of this dependency.\n")
}

func (s *Suite) TestVartypeCheck_FetchURL(c *check.C) {
	G.globalData.masterSiteUrls = map[string]string{
		"https://github.com/":         "MASTER_SITE_GITHUB",
		"http://ftp.gnu.org/pub/gnu/": "MASTER_SITE_GNU",
	}
	G.globalData.masterSiteVars = map[string]bool{
		"MASTER_SITE_GITHUB": true,
		"MASTER_SITE_GNU":    true,
	}

	newVartypeCheck("MASTER_SITES", "=", "https://github.com/example/project/").FetchURL()

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: Please use ${MASTER_SITE_GITHUB:=example/} instead of \"https://github.com/example/project/\".\n"+
		"WARN: fname:1: Run \""+confMake+" help topic=github\" for further tips.\n")

	newVartypeCheck("MASTER_SITES", "=", "http://ftp.gnu.org/pub/gnu/bison").FetchURL() // Missing a slash at the end

	c.Check(s.Output(), equals, "WARN: fname:1: Please use ${MASTER_SITE_GNU:=bison} instead of \"http://ftp.gnu.org/pub/gnu/bison\".\n")

	newVartypeCheck("MASTER_SITES", "=", "${MASTER_SITE_GNU:=bison}").FetchURL()

	c.Check(s.Output(), equals, "ERROR: fname:1: The subdirectory in MASTER_SITE_GNU must end with a slash.\n")

	newVartypeCheck("MASTER_SITES", "=", "${MASTER_SITE_INVALID:=subdir/}").FetchURL()

	c.Check(s.Output(), equals, "ERROR: fname:1: MASTER_SITE_INVALID does not exist.\n")
}

func (s *Suite) TestVartypeCheck_Message(c *check.C) {

	newVartypeCheck("SUBST_MESSAGE.id", "=", "\"Correct paths\"").Message()

	c.Check(s.Output(), equals, "WARN: fname:1: SUBST_MESSAGE.id should not be quoted.\n")

	newVartypeCheck("SUBST_MESSAGE.id", "=", "Correct paths").Message()

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestVartypeCheck_Pathlist(c *check.C) {

	newVartypeCheck("PATH", "=", "/usr/bin:/usr/sbin:.:${LOCALBASE}/bin").Pathlist()

	c.Check(s.Output(), equals, "WARN: fname:1: All components of PATH (in this case \".\") should be absolute paths.\n")
}

func (s *Suite) TestVartypeCheck_PkgRevision(c *check.C) {

	newVartypeCheck("PKGREVISION", "=", "3a").PkgRevision()

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: PKGREVISION must be a positive integer number.\n"+
		"ERROR: fname:1: PKGREVISION only makes sense directly in the package Makefile.\n")

	vc := newVartypeCheck("PKGREVISION", "=", "3")
	vc.line.fname = "Makefile"
	vc.PkgRevision()

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestVartypeCheck_SedCommands(c *check.C) {

	newVartypeCheck("SUBST_SED.dummy", "=", "s,@COMPILER@,gcc,g").SedCommands()

	c.Check(s.Output(), equals, "NOTE: fname:1: Please always use \"-e\" in sed commands, even if there is only one substitution.\n")

	newVartypeCheck("SUBST_SED.dummy", "=", "-e s,a,b, -e a,b,c,").SedCommands()

	c.Check(s.Output(), equals, "NOTE: fname:1: Each sed command should appear in an assignment of its own.\n")
}

func (s *Suite) TestVartypeCheck_Stage(c *check.C) {

	newVartypeCheck("SUBST_STAGE.dummy", "=", "post-patch").Stage()

	c.Check(s.Output(), equals, "")

	newVartypeCheck("SUBST_STAGE.dummy", "=", "post-modern").Stage()

	c.Check(s.Output(), equals, "WARN: fname:1: Invalid stage name \"post-modern\". Use one of {pre,do,post}-{extract,patch,configure,build,test,install}.\n")

	newVartypeCheck("SUBST_STAGE.dummy", "=", "pre-test").Stage()

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestVartypeCheck_Yes(c *check.C) {

	newVartypeCheck("APACHE_MODULE", "=", "yes").Yes()

	c.Check(s.Output(), equals, "")

	newVartypeCheck("APACHE_MODULE", "=", "no").Yes()

	c.Check(s.Output(), equals, "WARN: fname:1: APACHE_MODULE should be set to YES or yes.\n")

	newVartypeCheck("APACHE_MODULE", "=", "${YESVAR}").Yes()

	c.Check(s.Output(), equals, "WARN: fname:1: APACHE_MODULE should be set to YES or yes.\n")
}

func newVartypeCheck(varname, op, value string) *VartypeCheck {
	line := NewLine("fname", "1", "dummy", nil)
	valueNovar := withoutMakeVariables(line, value, true)
	return &VartypeCheck{line, varname, op, value, valueNovar, "", true, NOT_GUESSED}
}
