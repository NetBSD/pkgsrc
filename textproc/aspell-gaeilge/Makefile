# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:18 tv Exp $

DISTNAME=	aspell-gaeilge-2.0
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=   http://borel.slu.edu/~kps/ispell/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for aspell

USE_BUILDLINK3=	YES

ASPELLDATA=	${PREFIX}/share/aspell/

do-install:
	${INSTALL_DATA} ${WRKSRC}/gaeilge.dat ${ASPELLDATA}
	${INSTALL_DATA} ${WRKSRC}/gaeilge_phonet.dat ${ASPELLDATA}
	${INSTALL_DATA} ${WRKSRC}/gaeilge ${PREFIX}/lib/aspell

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
