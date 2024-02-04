# $NetBSD: Makefile,v 1.16 2024/02/04 00:03:31 markd Exp $

DISTNAME=	glossaries.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.53
TEXLIVE_REV=	68437

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/glossaries
COMMENT=	Documentation for tex-glossaries
LICENSE=	lppl-1.3c

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
