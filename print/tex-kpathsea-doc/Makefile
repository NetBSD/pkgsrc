# $NetBSD: Makefile,v 1.12 2013/11/17 17:12:19 minskim Exp $

DISTNAME=	kpathsea.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2013
TEXLIVE_REV=	30947

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-kpathsea
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	texlive-tetex<=2011nb1

INFO_FILES=	yes

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/info/[kw]* \
				texmf-dist/doc/man/man1/k* \
				texmf-dist/doc/man/man1/mko* \
				texmf-dist/doc/man/man1/mktex[l-z]* \
				texmf-dist/doc/man/man1/t*

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
