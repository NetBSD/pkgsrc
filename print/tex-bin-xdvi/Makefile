# $NetBSD: Makefile,v 1.3 2009/04/24 17:20:49 minskim Exp $
# TeX Live Revision 12778

DISTNAME=	bin-xdvi
PKGNAME=	tex-${DISTNAME}-22.84.14.12778

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Configuration file for xdvik

CONFLICTS+=	teTeX-bin<3.0nb25

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/xdvi/pixmaps texmf/xdvi/xdvi.cfg

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
