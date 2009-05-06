# $NetBSD: Makefile,v 1.7 2009/05/06 03:13:56 minskim Exp $
# TeX Live Revision 12897

DISTNAME=	bin-kpathsea
PKGNAME=	tex-${DISTNAME}-2008.12897

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Translation tables for TeX

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/fmtutil.cnf \
				texmf/web2c/mktex.opt \
				texmf/web2c/mktex[a-z]* \
				texmf/web2c/texmf.cnf

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
