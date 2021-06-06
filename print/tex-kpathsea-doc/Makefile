# $NetBSD: Makefile,v 1.22 2021/06/06 01:20:41 markd Exp $

DISTNAME=	kpathsea.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2021
TEXLIVE_REV=	59203

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/kpathsea
COMMENT=	Documentation for tex-kpathsea
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	texlive-tetex<=2011nb1

INFO_FILES=	yes

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/info/[kw]* \
				texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
