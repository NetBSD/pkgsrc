# $NetBSD: Makefile,v 1.2 2015/05/06 09:07:30 wiz Exp $

DISTNAME=	texmate
PKGNAME=	tex-${DISTNAME}-2
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texmate
COMMENT=	Comprehensive chess annotation in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-chessfss-[0-9]*:../../print/tex-skaknew
DEPENDS+=	tex-skak-[0-9]*:../../print/tex-skaknew

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
