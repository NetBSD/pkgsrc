# $NetBSD: build-type.awk,v 1.2 2022/02/07 02:39:41 pho Exp $
#
# Extract the field "Build-Type" out of a Cabal package description.
#
BEGIN {
    buildTypeLine = 0
}

tolower($1) ~ /^build-type:/ {
    if ($2) {
        print tolower($2);
        exit
    }
    else {
        buildTypeLine = 1;
        next
    }
}

buildTypeLine {
    print tolower($1);
    exit
}

END {
    # The package description didn't have Build-Type. Default to "Simple".
    print "simple"
}
