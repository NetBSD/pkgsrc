# $NetBSD: Makefile,v 1.4 2010/05/25 07:25:30 minskim Exp $

DISTNAME=	kpathsea.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009.16044
TEXLIVE_REV=	18027

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-kpathsea

INFO_FILES=	yes

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info/[kw]* \
				texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
