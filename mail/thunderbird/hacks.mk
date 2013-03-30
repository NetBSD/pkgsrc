# $NetBSD: hacks.mk,v 1.3 2013/03/30 23:31:36 tron Exp $

# workround for link of thunderbird-bin etc.
LDFLAGS+=	-Wl,-R${PREFIX}/lib/thunderbird

.include "../../devel/xulrunner/hacks.mk"
