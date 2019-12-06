# $NetBSD: Makefile,v 1.2 2019/12/06 19:32:24 markd Exp $

DISTNAME=	sansmathaccent
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	30187

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/sansmathaccent
COMMENT=	Correct placement of accents in sans-serif maths
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	sansmathaccent.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
