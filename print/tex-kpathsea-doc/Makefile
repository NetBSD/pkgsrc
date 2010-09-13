# $NetBSD: Makefile,v 1.5 2010/09/13 22:33:31 minskim Exp $

DISTNAME=	kpathsea.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2010
TEXLIVE_REV=	19287

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-kpathsea

INFO_FILES=	yes

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info/[kw]* \
				texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
