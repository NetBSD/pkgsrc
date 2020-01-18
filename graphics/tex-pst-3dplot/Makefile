# $NetBSD: Makefile,v 1.6 2020/01/18 23:32:30 rillig Exp $

DISTNAME=	pst-3dplot
PKGNAME=	tex-${DISTNAME}-2.04
TEXLIVE_REV=	43703

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pst-3dplot
COMMENT=	Draw 3D objects in parallel projection, using PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-3d-[0-9]*:../../graphics/tex-pst-3d
DEPENDS+=	tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=	tex-pst-plot-[0-9]*:../../graphics/tex-pst-plot
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
