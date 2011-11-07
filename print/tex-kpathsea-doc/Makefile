# $NetBSD: Makefile,v 1.10 2011/11/07 08:29:14 minskim Exp $

DISTNAME=	kpathsea.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2011
TEXLIVE_REV=	24417

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-kpathsea

INFO_FILES=	yes

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info/[kw]* \
				texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
