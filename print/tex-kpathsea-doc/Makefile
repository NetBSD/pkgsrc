# $NetBSD: Makefile,v 1.15 2015/06/14 12:50:03 markd Exp $

DISTNAME=	kpathsea.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2015
TEXLIVE_REV=	37193

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/kpathsea
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
