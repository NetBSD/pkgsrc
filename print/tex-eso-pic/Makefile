# $NetBSD: Makefile,v 1.5 2015/08/02 12:09:44 markd Exp $

DISTNAME=	eso-pic
PKGNAME=	tex-${DISTNAME}-2.0g
TEXLIVE_REV=	37925

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
