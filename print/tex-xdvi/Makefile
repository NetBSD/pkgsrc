# $NetBSD: Makefile,v 1.7 2017/06/21 13:25:35 markd Exp $

DISTNAME=	xdvi
PKGNAME=	tex-${DISTNAME}-22.87.03
TEXLIVE_REV=	44166

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xdvi
COMMENT=	Configuration file for xdvik

CONFLICTS+=	teTeX-bin<3.0nb25
SUPERSEDES=	tex-bin-xdvi<=22.84.14.12778nb1

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/xdvi/pixmap texmf-dist/dvips/xdvi

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
