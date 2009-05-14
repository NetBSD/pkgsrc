# $NetBSD: Makefile,v 1.7 2009/05/14 04:44:33 minskim Exp $
# TeX Live Revision 12897

DISTNAME=	bin-tetex
PKGNAME=	tex-${DISTNAME}-3.0.12897

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/updmap.cfg

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
