# $NetBSD: Makefile,v 1.2 2016/01/30 04:05:51 markd Exp $

DISTNAME=	pst-2dplot
PKGNAME=	tex-${DISTNAME}-1.5
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PSTricks package for drawing 2D curves
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pst-plot-[0-9]*:../../graphics/tex-pst-plot
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
