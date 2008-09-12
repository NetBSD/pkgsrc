# $NetBSD: Makefile,v 1.13 2008/09/12 11:58:50 gdt Exp $
#

DISTNAME=		sysinfo-3.5.1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.rge.com/pub/admin/sysinfo/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.magnicomp.com/
COMMENT=		Displays system hardware and software information and configuration

LICENSE=		sysinfo-license
RESTRICTED=		May not be sold for profit or used for commercial gain.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	SunOS-*-*      # only for Solaris, at the moment

BUILD_TARGET=		default
INSTALL_TARGET=		install install.man
TEST_TARGET=		test
MAKE_ENV+=		CPPFLAGS="" CC=${CC:Q}

post-build:
	${CHMOD} -R o+rx ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
