# $NetBSD: Makefile,v 1.3 2002/08/16 03:12:14 jschauma Exp $

DISTNAME=	aspell-gaeilge-2.0
CATEGORIES=	textproc
MASTER_SITES=   http://borel.slu.edu/~kps/ispell/

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for aspell

DEPENDS+=	aspell>=0.33.7.1:../../textproc/aspell

ASPELLDATA=${PREFIX}/share/aspell/

do-configure:
	${ECHO} ${PREFIX}/lib/aspell/gaeilge > \
		${WRKSRC}/ga-gaeilge-aspell.pwli

do-install:
	${INSTALL_DATA} ${WRKSRC}/gaeilge.dat ${ASPELLDATA}
	${INSTALL_DATA} ${WRKSRC}/gaeilge_phonet.dat ${ASPELLDATA}
	${INSTALL_DATA} ${WRKSRC}/gaeilge ${PREFIX}/lib/aspell
	${INSTALL_DATA} ${WRKSRC}/ga-gaeilge-aspell.pwli ${PREFIX}/share/pspell

.include "../../mk/bsd.pkg.mk"
