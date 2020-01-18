# $NetBSD: Makefile,v 1.7 2020/01/18 23:34:52 rillig Exp $

DISTNAME=	t2
PKGNAME=	tex-${DISTNAME}-2018.47870
TEXLIVE_REV=	47870

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/t2
COMMENT=	Support for using T2 encoding
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
