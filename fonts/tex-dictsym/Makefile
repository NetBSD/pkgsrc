# $NetBSD: Makefile,v 1.6 2026/03/26 08:50:36 markd Exp $

DISTNAME=	dictsym
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	78251

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dictsym
COMMENT=	DictSym font and macro package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss

TEX_MAP_FILES+=	dictsym.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
