# $NetBSD: Makefile,v 1.3 2016/01/30 04:05:53 markd Exp $

DISTNAME=	pst-poly
PKGNAME=	tex-${DISTNAME}-1.63
TEXLIVE_REV=	35062

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Polygons with PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
