# $NetBSD: Makefile,v 1.5 2003/01/17 01:23:23 salo Exp $

DISTNAME=	aspell-gaeilge-2.0
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=   http://borel.slu.edu/~kps/ispell/

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://borel.slu.edu/~kps/ispell/
COMMENT=	Irish language support for aspell

USE_BUILDLINK2=	YES

ASPELLDATA=	${PREFIX}/share/aspell/

do-install:
	${INSTALL_DATA} ${WRKSRC}/gaeilge.dat ${ASPELLDATA}
	${INSTALL_DATA} ${WRKSRC}/gaeilge_phonet.dat ${ASPELLDATA}
	${INSTALL_DATA} ${WRKSRC}/gaeilge ${PREFIX}/lib/aspell

.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
