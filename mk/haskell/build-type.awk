# $NetBSD: build-type.awk,v 1.1 2021/05/01 15:06:26 pho Exp $
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
