# $NetBSD: Makefile,v 1.12 2004/10/03 00:13:16 tv Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=		pilot-link-libs-${PILOT_LINK_VERS}
PKGREVISION=		2
COMMENT=		Libraries for talking to the 3Com Pilot PDA

CONFLICTS+=		pilot-link-0.8.* pilot-link-0.9.[0-3]

USE_BUILDLINK3=		yes

MAKE_ENV+=		PILIB="libsock/libpisock.la"
MAKE_ENV+=		PICCLIB="libcc/libpicc.a"

BUILD_DIRS=		${WRKSRC}/include
BUILD_DIRS+=		${WRKSRC}/libpisock
BUILD_DIRS+=		${WRKSRC}/libpisock++
BUILD_DIRS+=		${WRKSRC}/libpisync

.include "../../devel/ncurses/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
