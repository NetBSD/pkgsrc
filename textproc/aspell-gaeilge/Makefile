# $NetBSD: Makefile,v 1.8 2004/02/11 04:35:20 xtraeme Exp $

DISTNAME=	aspell-gaeilge-2.0
PKGREVISION=	3
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
