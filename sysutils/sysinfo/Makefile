# $NetBSD: Makefile,v 1.19 2026/02/10 08:14:38 wiz Exp $

DISTNAME=		sysinfo-3.5.1
CATEGORIES=		sysutils
#MASTER_SITES=		ftp://ftp.rge.com/pub/admin/sysinfo/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.magnicomp.com/
COMMENT=		Displays system hardware and software information and configuration
LICENSE=		sysinfo-license

RESTRICTED=		May not be sold for profit or used for commercial gain.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	SunOS-*-*      # only for Solaris, at the moment

BUILD_TARGET=		default
INSTALL_TARGET=		install install.man
TEST_TARGET=		test
MAKE_ENV+=		CPPFLAGS="" CC=${CC:Q} KISA=${MACHINE_ARCH}

.include "../../mk/bsd.pkg.mk"
