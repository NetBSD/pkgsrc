# $NetBSD: Makefile,v 1.15 2023/04/01 11:20:18 markd Exp $

DISTNAME=	glossaries.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.52
TEXLIVE_REV=	64919

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/glossaries
COMMENT=	Documentation for tex-glossaries
LICENSE=	lppl-1.3c

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
