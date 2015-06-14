# $NetBSD: Makefile,v 1.4 2015/06/14 12:50:02 markd Exp $

DISTNAME=	eso-pic
PKGNAME=	tex-${DISTNAME}-2.0e
TEXLIVE_REV=	36994

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/eso-pic
COMMENT=	Add picture commands (or backgrounds) to every page
LICENSE=	lppl-1.2

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
