# $NetBSD: Makefile,v 1.1.1.1 2002/08/02 01:54:13 jschauma Exp $
#

DISTNAME=	ispellca
PKGNAME=	ispell-catalan-0.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.softcatala.org/cgi-bin/gaudi/contadorb/load.cgi?/fitxers/llengua/
EXTRACT_SUFX=	.zip

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.softcatala.org/prog24.htm
COMMENT=	Catalan dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/buildhash catala catala.aff catala.hash

do-install:
	${INSTALL_DATA} ${WRKSRC}/catala.aff ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/catala.hash ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
