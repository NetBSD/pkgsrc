# $NetBSD: Makefile,v 1.14 2005/03/20 21:47:35 schwarz Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=		pilot-link-libs-${PILOT_LINK_VERS}
PKGREVISION=		3
COMMENT=		Libraries for talking to the 3Com Pilot PDA

CONFLICTS+=		pilot-link-0.8.* pilot-link-0.9.[0-3]

USE_BUILDLINK3=		yes

MAKE_ENV+=		PILIB="libsock/libpisock.la"
MAKE_ENV+=		PICCLIB="libcc/libpicc.a"

.if ${LOWER_OPSYS} == "irix5.3"
CONFIGURE_ENV+=		ac_cv_header_inttypes_h="no"
.endif

BUILD_DIRS=		${WRKSRC}/include
BUILD_DIRS+=		${WRKSRC}/libpisock
BUILD_DIRS+=		${WRKSRC}/libpisock++
BUILD_DIRS+=		${WRKSRC}/libpisync

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
