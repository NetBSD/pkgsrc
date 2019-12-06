# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:28 markd Exp $

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

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
