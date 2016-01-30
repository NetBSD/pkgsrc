# $NetBSD: Makefile,v 1.3 2016/01/30 04:05:51 markd Exp $

DISTNAME=	pst-3dplot
PKGNAME=	tex-${DISTNAME}-2.01
TEXLIVE_REV=	35042

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Draw 3D objects in parallel projection, using PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-3d-[0-9]*:../../graphics/tex-pst-3d
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pst-plot-[0-9]*:../../graphics/tex-pst-plot
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
