# $NetBSD: disable-components.awk,v 1.1 2024/05/04 11:21:26 pho Exp $
#
# Prevent executables specified with -v "exe=foo bar ..." from being built
# or installed. Do the same for libraries specified with -v "exe=foo bar
# ...".
#
BEGIN {
    split(exe, exev, /[[:space:]]+/);
    split(lib, libv, /[[:space:]]+/);
}

{
    print;

    matched = 0;
    if (tolower($1) == "executable") {
        for (i in exev) {
            if (exev[i] == $2) {
                matched = 1;
                break;
            }
        }
    }
    else if (tolower($1) == "library") {
        for (i in libv) {
            if (libv[i] == $2) {
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
            print "Invalid cabal file: premature end of file right after \"executable\" or \"library\" line." > "/dev/stderr"
            exit 1
        }
    }
}
