# $NetBSD: Makefile,v 1.3 2015/05/19 20:42:06 bad Exp $

DISTNAME=	texmate
PKGNAME=	tex-${DISTNAME}-2
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texmate
COMMENT=	Comprehensive chess annotation in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-chessfss-[0-9]*:../../print/tex-chessfss
DEPENDS+=	tex-skak-[0-9]*:../../print/tex-skak

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
