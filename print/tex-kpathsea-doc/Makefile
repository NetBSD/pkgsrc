# $NetBSD: Makefile,v 1.3 2010/04/16 18:38:56 minskim Exp $
# TeX Live Revision 17541

DISTNAME=	kpathsea.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009.16044
DIST_SUBDIR=	${PKGNAME:S/16044/17541/}

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-kpathsea

INFO_FILES=	yes

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info/[kw]* \
				texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
