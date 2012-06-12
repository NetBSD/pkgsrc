# $NetBSD: hacks.mk,v 1.2 2012/06/12 19:37:49 ryoon Exp $

# workround for link of thunderbird-bin etc.
LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib/thunderbird

.include "../../devel/xulrunner/hacks.mk"
