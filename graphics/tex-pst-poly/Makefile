# $NetBSD: Makefile,v 1.1.1.1 2011/03/18 21:39:18 minskim Exp $

DISTNAME=	pst-poly
PKGNAME=	tex-${DISTNAME}-1.61
TEXLIVE_REV=	16460

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Polygons with PSTricks

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
