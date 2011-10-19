# $NetBSD: Makefile,v 1.1.1.1 2011/10/19 20:11:45 minskim Exp $

DISTNAME=	ttfutils
PKGNAME=	tex-${DISTNAME}-2011
TEXLIVE_REV=	23089

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Data files for TeX Live TTF utilities

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
