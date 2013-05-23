# $NetBSD: hacks.mk,v 1.4 2013/05/23 13:14:28 ryoon Exp $

# workround for link of thunderbird-bin etc.
LDFLAGS+=	-Wl,-R${PREFIX}/lib/thunderbird

.include "../../devel/xulrunner17/hacks.mk"
