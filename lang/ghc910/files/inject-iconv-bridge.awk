# $NetBSD: inject-iconv-bridge.awk,v 1.1 2025/01/29 13:21:53 pho Exp $

BEGIN {
    replaced = 0;
}

/^exec / {
    print $0 " -optl-lc -optl-L" WRKDIR " -optl-liconv-bridge";
    replaced = 1;
    next;
}

{
    print $0;
}

END {
    if (!replaced) {
        print "[inject-iconv-bridge.awk] cannot find where to inject args" > "/dev/stderr";
        exit 1;
    }
}
