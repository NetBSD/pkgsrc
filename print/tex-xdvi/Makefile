# $NetBSD: Makefile,v 1.9 2019/12/06 20:23:44 markd Exp $

DISTNAME=	xdvi
PKGNAME=	tex-${DISTNAME}-22.87.03
TEXLIVE_REV=	44166

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xdvi
COMMENT=	Configuration file for xdvik

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/xdvi/pixmap texmf-dist/dvips/xdvi

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
