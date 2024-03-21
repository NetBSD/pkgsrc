# $NetBSD: Makefile,v 1.27 2024/03/21 09:21:13 markd Exp $

DISTNAME=	kpathsea.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2024
TEXLIVE_REV=	70681

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/kpathsea
COMMENT=	Documentation for tex-kpathsea
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	texlive-tetex<=2011nb1

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/info \
				texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
