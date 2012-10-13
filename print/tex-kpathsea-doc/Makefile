# $NetBSD: Makefile,v 1.11 2012/10/13 22:50:06 minskim Exp $

DISTNAME=	kpathsea.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2012
TEXLIVE_REV=	27341

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-kpathsea
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	texlive-tetex<=2011nb1

INFO_FILES=	yes

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info/[kw]* \
				texmf/doc/man/man1/k* \
				texmf/doc/man/man1/mko* \
				texmf/doc/man/man1/mktex[l-z]* \
				texmf/doc/man/man1/t*

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
