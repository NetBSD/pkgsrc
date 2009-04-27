# $NetBSD: Makefile,v 1.6 2009/04/27 16:07:00 minskim Exp $
# TeX Live Revision 12785

DISTNAME=	bin-tetex
PKGNAME=	tex-${DISTNAME}-3.0.12785

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/updmap.cfg

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
