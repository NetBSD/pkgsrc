# $NetBSD: Makefile,v 1.5 2009/04/13 00:13:03 minskim Exp $
# TeX Live Revision 12298

DISTNAME=	bin-tetex
PKGNAME=	tex-${DISTNAME}-3.0.12298

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/updmap.cfg

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
