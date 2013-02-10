# $NetBSD: plist-cygwin.awk,v 1.1 2013/02/10 12:03:00 obache Exp $
#
### Executable binary files on Cygwin:
###    Executable binary files have .exe suffix.
###    Cygwin's /bin/install automatically adds .exe when necessary.
###    "test -f foo" succeeds when foo.exe exists.
###    So it is supposed that if foo.exe and foo have same device and inode
###    number, then only foo.exe exists.
###    It may be result in false detect if foo is hard link of foo.exe,
###    but it is hard to create such hard link, and if foo.exe exists,
###    foo will not be requred.

BEGIN {
	PREFIX = ENVIRON["PREFIX"] ? ENVIRON["PREFIX"] : "/usr/pkg"
	TEST = ENVIRON["TEST"] ? ENVIRON["TEST"] : "test"
}

!/^@/ {
	cmd = TEST " " PREFIX "/" $0 " -ef " PREFIX "/" $0 ".exe"
	if (system(cmd) == 0) {
		$0 = $0 ".exe"
	}
}
