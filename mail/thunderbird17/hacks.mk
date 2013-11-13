# $NetBSD: hacks.mk,v 1.1 2013/11/13 13:27:45 ryoon Exp $

# workround for link of thunderbird-bin etc.
LDFLAGS+=	-Wl,-R${PREFIX}/lib/thunderbird

.include "../../devel/xulrunner17/hacks.mk"
