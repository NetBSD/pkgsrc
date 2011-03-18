# $NetBSD: Makefile,v 1.1.1.1 2011/03/18 19:49:23 minskim Exp $

DISTNAME=	pst-3dplot
PKGNAME=	tex-${DISTNAME}-1.94
TEXLIVE_REV=	21588

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Draw 3d curves and graphs using PSTricks

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-3d-[0-9]*:../../graphics/tex-pst-3d
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pst-plot-[0-9]*:../../graphics/tex-pst-plot
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
