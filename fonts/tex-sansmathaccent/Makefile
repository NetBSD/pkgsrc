# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:51 rillig Exp $

DISTNAME=	sansmathaccent
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	30187

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/sansmathaccent
COMMENT=	Correct placement of accents in sans-serif maths
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	sansmathaccent.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
