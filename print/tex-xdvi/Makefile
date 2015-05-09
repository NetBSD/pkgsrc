# $NetBSD: Makefile,v 1.5 2015/05/09 01:19:26 markd Exp $

DISTNAME=	xdvi
PKGNAME=	tex-${DISTNAME}-22.87
PKGREVISION=	1
TEXLIVE_REV=	33736

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xdvi
COMMENT=	Configuration file for xdvik

CONFLICTS+=	teTeX-bin<3.0nb25
SUPERSEDES=	tex-bin-xdvi<=22.84.14.12778nb1
DEPENDS+=	xdvik>=22.87:../../print/xdvik

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/xdvi/pixmap texmf-dist/dvips/xdvi

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
