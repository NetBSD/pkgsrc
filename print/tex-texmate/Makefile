# $NetBSD: Makefile,v 1.1.1.1 2011/02/15 11:38:35 wiz Exp $

DISTNAME=	texmate
PKGNAME=	tex-${DISTNAME}-2
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Comprehensive chess annotation in LaTeX

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-chessfss-[0-9]*:../../print/tex-skaknew
DEPENDS+=	tex-skak-[0-9]*:../../print/tex-skaknew

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
