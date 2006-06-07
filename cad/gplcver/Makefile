# $NetBSD: Makefile,v 1.3 2006/06/07 23:52:17 minskim Exp $
#

DISTNAME=		gplcver-2.11a.src
PKGNAME=		gplcver-2.11a
CATEGORIES=		cad
MASTER_SITES=		http://www.pragmatic-c.com/gpl-cver/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pragmatic-c.com/gpl-cver/
COMMENT=		Verilog simulator

BUILD_DIRS=		src
MAKEFILE=		makefile.freebsd
BUILDLINK_LIBS.dl=	${BUILDLINK_LDADD.dl}

.include "../../mk/dlopen.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cver ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gplcver/pli_incs
	${INSTALL_DATA} ${WRKSRC}/pli_incs/*.h ${PREFIX}/lib/gplcver/pli_incs

.include "../../mk/bsd.pkg.mk"
