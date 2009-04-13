# $NetBSD: Makefile,v 1.3 2009/04/13 00:13:03 minskim Exp $
# TeX Live Revision 12509

DISTNAME=	bin-kpathsea
PKGNAME=	tex-${DISTNAME}-2008.12509

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Translation tables for TeX

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/fmtutil.cnf \
				texmf/web2c/mktex.opt \
				texmf/web2c/mktex[a-z]* \
				texmf/web2c/texmf.cnf

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
