# $NetBSD: Makefile,v 1.2 2010/09/24 21:26:28 minskim Exp $

DISTNAME=	xdvi
PKGNAME=	tex-${DISTNAME}-22.84.16
PKGREVISION=	1
TEXLIVE_REV=	18835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Configuration file for xdvik

CONFLICTS+=	teTeX-bin<3.0nb25
SUPERSEDES=	tex-bin-xdvi<=22.84.14.12778nb1

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/xdvi/pixmap texmf/xdvi/xdvi.cfg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
