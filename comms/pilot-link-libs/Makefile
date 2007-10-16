# $NetBSD: Makefile,v 1.18 2007/10/16 23:56:02 tnn Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=		pilot-link-libs-${PILOT_LINK_VERS}
COMMENT=		Libraries for talking to the 3Com Pilot PDA

CONFLICTS+=		pilot-link<0.9.5

MAKE_ENV+=		PILIB="libsock/libpisock.la"
MAKE_ENV+=		PICCLIB="libcc/libpicc.a"

.if !empty(MACHINE_PLATFORM:MIRIX-5.3-*)
CONFIGURE_ENV+=		ac_cv_header_inttypes_h="no"
.endif

BUILD_DIRS=		${WRKSRC}/include
BUILD_DIRS+=		${WRKSRC}/libpisock
BUILD_DIRS+=		${WRKSRC}/libpisync

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
