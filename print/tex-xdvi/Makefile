# $NetBSD: Makefile,v 1.3 2013/11/17 16:55:27 minskim Exp $

DISTNAME=	xdvi
PKGNAME=	tex-${DISTNAME}-22.86
TEXLIVE_REV=	30339

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Configuration file for xdvik

CONFLICTS+=	teTeX-bin<3.0nb25
SUPERSEDES=	tex-bin-xdvi<=22.84.14.12778nb1

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/xdvi/pixmap texmf-dist/dvips/xdvi

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
