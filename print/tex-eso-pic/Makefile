# $NetBSD: Makefile,v 1.2 2011/03/16 17:41:37 minskim Exp $

DISTNAME=	eso-pic
PKGNAME=	tex-${DISTNAME}-2.0c
PKGREVISION=	1
TEXLIVE_REV=	21515

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Add picture commands (or backgrounds) to every page

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
