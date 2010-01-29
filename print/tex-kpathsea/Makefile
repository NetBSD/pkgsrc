# $NetBSD: Makefile,v 1.1.1.1 2010/01/29 02:32:55 minskim Exp $
# TeX Live Revision 16044

DISTNAME=	kpathsea
PKGNAME=	tex-${DISTNAME}-2009.16044

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Translation tables for TeX

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/fmtutil.cnf \
				texmf/web2c/mktex.opt \
				texmf/web2c/mktex[a-z]* \
				texmf/web2c/texmf.cnf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
