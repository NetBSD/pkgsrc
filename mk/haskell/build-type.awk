# $NetBSD: build-type.awk,v 1.3 2022/02/07 02:43:42 pho Exp $
#
# Extract the field "Build-Type" out of a Cabal package description.
#
BEGIN {
    buildTypeLine = 0
    found = 0
}

tolower($1) ~ /^build-type:/ {
    if ($2) {
        found = 1;
        print tolower($2);
        exit
    }
    else {
        buildTypeLine = 1;
        next
    }
}

buildTypeLine {
    found = 1;
    print tolower($1);
    exit
}

END {
    if (!found) {
        # The package description didn't have Build-Type. Default to "Simple".
        print "simple"
    }
}
