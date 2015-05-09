# $NetBSD: Makefile,v 1.6 2015/05/09 20:29:41 markd Exp $

DISTNAME=	xdvi
PKGNAME=	tex-${DISTNAME}-22.87
PKGREVISION=	2
TEXLIVE_REV=	33736

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xdvi
COMMENT=	Configuration file for xdvik

CONFLICTS+=	teTeX-bin<3.0nb25
SUPERSEDES=	tex-bin-xdvi<=22.84.14.12778nb1

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/xdvi/pixmap texmf-dist/dvips/xdvi

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
