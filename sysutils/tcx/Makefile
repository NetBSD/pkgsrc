# $NetBSD: Makefile,v 1.2 2003/07/17 22:53:53 grant Exp $

DISTNAME=	tcx-linux
PKGNAME=	tcx-19940124
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ibiblio.unc.edu/pub/Linux/utils/compress/

MAINTAINER=	packages@NetBSD.org
#HOMEPAGE=	
COMMENT=	transparently compress executables

WRKSRC=		${WRKDIR}/tcx

post-patch:
	cd ${WRKSRC}; ${MV} config.h config.h-pre; ${SED} -e 's|@PREFIX@|"${PREFIX}"|g' < config.h-pre > config.h

.include "../../mk/bsd.pkg.mk"
