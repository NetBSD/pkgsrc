# $NetBSD: Makefile,v 1.8 2010/11/17 19:29:03 minskim Exp $

DISTNAME=	kpathsea
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	19875

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Translation tables for TeX

CONFLICTS+=	tex-bin-kpathsea-[0-9]*
SUPERSEDES=	tex-bin-kpathsea<=2008.12897

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/fmtutil.cnf \
				texmf/web2c/mktex.opt \
				texmf/web2c/mktex[a-z]* \
				texmf/web2c/texmf.cnf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
