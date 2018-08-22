# $NetBSD: Makefile,v 1.26 2018/08/22 09:43:04 wiz Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=		pilot-link-libs-${PILOT_LINK_VERS}
PKGREVISION=		2
COMMENT=		Libraries for talking to the 3Com Pilot PDA

CONFLICTS+=		pilot-link<0.9.5

MAKE_ENV+=		PILIB="libsock/libpisock.la"
MAKE_ENV+=		PICCLIB="libcc/libpicc.a"

.if !empty(MACHINE_PLATFORM:MIRIX-5.3-*)
CONFIGURE_ENV+=		ac_cv_header_inttypes_h="no"
.endif

BUILD_DIRS=		include libpisock libpisync

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
