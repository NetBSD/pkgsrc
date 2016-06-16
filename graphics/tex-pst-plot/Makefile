# $NetBSD: Makefile,v 1.4 2016/06/16 04:00:47 markd Exp $

DISTNAME=	pst-plot
PKGNAME=	tex-${DISTNAME}-1.75
TEXLIVE_REV=	41242

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Plot data using PSTricks
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
