# $NetBSD: Makefile,v 1.2 2013/04/24 11:15:45 rodent Exp $
#

DISTNAME=	ispell-sc-ca
PKGNAME=	${DISTNAME:S/-sc//1}-1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.softcatala.org/cgi-bin/gaudi/contadorb/load.cgi?/fitxers/linux/
EXTRACT_SUFX=	.zip

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.softcatala.org/projectes/myspell/
COMMENT=	Catalan dictionary for interactive spelling checker

CONFLICTS+=	ispell-catalan-[0-9]*
DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

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
	${INSTALL_DATA} ${WRKSRC}/catala.aff ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/catala.hash ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
