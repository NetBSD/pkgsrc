# $NetBSD: Makefile,v 1.1.1.1 2011/03/17 18:23:47 minskim Exp $

DISTNAME=	pst-plot
PKGNAME=	tex-${DISTNAME}-1.26
TEXLIVE_REV=	21177

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Plot data using PSTricks

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
