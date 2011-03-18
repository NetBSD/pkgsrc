# $NetBSD: Makefile,v 1.1.1.1 2011/03/18 21:45:03 minskim Exp $

DISTNAME=	pstricks-add
PKGNAME=	tex-${DISTNAME}-3.51
TEXLIVE_REV=	21290

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Collection of add-ons and bugfixes for PSTricks

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-3d-[0-9]*:../../graphics/tex-pst-3d
DEPENDS+=	tex-pst-math-[0-9]*:../../graphics/tex-pst-math
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pst-plot-[0-9]*:../../graphics/tex-pst-plot
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
