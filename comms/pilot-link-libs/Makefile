# $NetBSD: Makefile,v 1.5 2002/09/10 16:06:36 wiz Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=		pilot-link-libs-${PILOT_LINK_VERS}
PKGREVISION=		3
COMMENT=		Libraries for talking to the 3Com Pilot PDA

CONFLICTS+=		pilot-link-0.8.* pilot-link-0.9.[0-3]

USE_BUILDLINK_ONLY=	# defined

MAKE_ENV+=		PILIB="libsock/libpisock.la"
MAKE_ENV+=		PICCLIB="libcc/libpicc.a"

ALL_TARGET=		libs
INSTALL_TARGET=		install-libs

.include "../../converters/libiconv/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
