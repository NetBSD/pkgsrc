# $NetBSD: Makefile,v 1.5 2020/01/18 23:34:55 rillig Exp $

DISTNAME=	texmate
PKGNAME=	tex-${DISTNAME}-2
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/texmate
COMMENT=	Comprehensive chess annotation in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-chessfss-[0-9]*:../../print/tex-chessfss
DEPENDS+=	tex-skak-[0-9]*:../../print/tex-skak

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
