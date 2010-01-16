# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 03:54:15 minskim Exp $
# TeX Live Revision 16044

DISTNAME=	xdvi
PKGNAME=	tex-${DISTNAME}-22.84.16

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Configuration file for xdvik

CONFLICTS+=	teTeX-bin<3.0nb25
SUPERSEDES=	tex-bin-xdvi<=22.84.14.12778nb1

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/xdvi/pixmaps texmf/xdvi/xdvi.cfg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
