# $NetBSD: hacks.mk,v 1.2 2013/11/29 12:59:12 joerg Exp $

# workround for link of thunderbird-bin etc.
LDFLAGS+=	-Wl,-R${PREFIX}/lib/thunderbird17

.include "../../devel/xulrunner17/hacks.mk"
