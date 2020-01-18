# $NetBSD: Makefile,v 1.12 2020/01/18 23:34:14 rillig Exp $

DISTNAME=	glossaries.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.42
TEXLIVE_REV=	49618

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/glossaries
COMMENT=	Documentation for tex-glossaries
LICENSE=	lppl-1.3c

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
