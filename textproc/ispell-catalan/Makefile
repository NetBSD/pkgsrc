# $NetBSD: Makefile,v 1.7 2005/06/17 03:50:36 jlam Exp $
#

DISTNAME=	ispell-sc-ca
PKGNAME=	ispell-catalan-1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.softcatala.org/cgi-bin/gaudi/contadorb/load.cgi?/fitxers/linux/
EXTRACT_SUFX=	.zip

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.softcatala.org/projectes/myspell/
COMMENT=	Catalan dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	lib

post-extract:
	( cd ${WRKSRC} 							\
		&& ${MV} catalan_i.dic catala.dic && 			\
		${MV} catalan_i.aff catala.aff )

do-build:
	( cd ${WRKSRC} && 						\
		${PREFIX}/bin/buildhash catala.dic catala.aff 		\
			catala.hash )

do-install:
	${INSTALL_DATA} ${WRKSRC}/catala.aff ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/catala.hash ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
