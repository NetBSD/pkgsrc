# $NetBSD: Makefile,v 1.9 2003/12/08 21:48:09 reed Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=		pilot-link-libs-${PILOT_LINK_VERS}
PKGREVISION=		1
COMMENT=		Libraries for talking to the 3Com Pilot PDA

CONFLICTS+=		pilot-link-0.8.* pilot-link-0.9.[0-3]

USE_BUILDLINK2=		# defined

MAKE_ENV+=		PILIB="libsock/libpisock.la"
MAKE_ENV+=		PICCLIB="libcc/libpicc.a"

BUILD_DIRS=		${WRKSRC}/include
BUILD_DIRS+=		${WRKSRC}/libpisock
BUILD_DIRS+=		${WRKSRC}/libpisock++
BUILD_DIRS+=		${WRKSRC}/libpisync

.include "../../devel/ncurses/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
