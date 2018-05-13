# $NetBSD: Makefile,v 1.17 2018/05/13 11:24:44 markd Exp $

DISTNAME=	kpathsea.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2018
TEXLIVE_REV=	47198

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/kpathsea
COMMENT=	Documentation for tex-kpathsea
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	texlive-tetex<=2011nb1

INFO_FILES=	yes

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/info/[kw]* \
				texmf-dist/doc/man/man1/k* \
				texmf-dist/doc/man/man1/mko* \
				texmf-dist/doc/man/man1/mktex[l-z]* \
				texmf-dist/doc/man/man1/t*

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
