# $NetBSD: Makefile,v 1.7 2008/11/12 13:37:36 gson Exp $
#

DISTNAME=		garmin-utils-2.4
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.snafu.org/pub/

MAINTAINER=		gson@NetBSD.org
HOMEPAGE=		http://www.snafu.org/
COMMENT=		Utilities for Garmin GPS receivers

ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-*

MAKE_FLAGS+=		MKCATPAGES=no
INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "Linux")
USE_TOOLS+=		gmake
MAKE_FILE=		GNUmakefile

do-install:
			${INSTALL_PROGRAM} ${WRKSRC}/gardump/gardump ${PREFIX}/bin
			${INSTALL_MAN} ${WRKSRC}/gardump/gardump.1 ${PREFIX}/${PKGMANDIR}/man1
			${INSTALL_PROGRAM} ${WRKSRC}/garload/garload ${PREFIX}/bin
			${INSTALL_MAN} ${WRKSRC}/garload/garload.1 ${PREFIX}/${PKGMANDIR}/man1
			${INSTALL_LIB} ${WRKSRC}/lib/libgarmin.a ${PREFIX}/lib
.endif

.include "../../mk/bsd.pkg.mk"
