# $NetBSD: Makefile,v 1.3 2010/02/21 16:01:34 minskim Exp $
# TeX Live Revision 17032

DISTNAME=	kpathsea
PKGNAME=	tex-${DISTNAME}-2009.16044
DIST_SUBDIR=	${PKGNAME:S/16044/17032/}

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
