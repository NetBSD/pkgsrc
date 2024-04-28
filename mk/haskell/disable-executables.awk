# $NetBSD: disable-executables.awk,v 1.2 2024/04/28 14:17:49 pho Exp $
#
# Prevent executables specified with -v "exec=foo bar ..." from being built
# or installed.
#
BEGIN {
    split(exec, execv, /[[:space:]]+/);
}

{
    print;

    matched = 0;
    if (tolower($1) == "executable") {
        for (i in execv) {
            if (execv[i] == $2) {
                matched = 1;
                break;
            }
        }
    }
    if (matched) {
        # The Cabal format requires that indentation levels are
        # aligned. Read the next line and use the same indentation for
        # "buildable: False".
        if ((getline next_line) > 0) {
            match(next_line, /[[:space:]]+/);
            print substr(next_line, RSTART, RLENGTH) "buildable: False";
            print next_line;
        }
        else {
            print "Invalid cabal file: premature end of file right after \"executable\" line." > "/dev/stderr"
            exit 1
        }
    }
}
