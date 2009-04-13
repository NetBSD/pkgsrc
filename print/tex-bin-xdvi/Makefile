# $NetBSD: Makefile,v 1.2 2009/04/13 00:13:03 minskim Exp $
# TeX Live Revision 10592

DISTNAME=	bin-xdvi
PKGNAME=	tex-${DISTNAME}-22.84.14

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Configuration file for xdvik

CONFLICTS+=	teTeX-bin<3.0nb25

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/xdvi/pixmaps texmf/xdvi/xdvi.cfg

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
