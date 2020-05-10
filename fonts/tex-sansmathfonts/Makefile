# $NetBSD: Makefile,v 1.6 2020/05/10 04:31:53 markd Exp $

DISTNAME=	sansmathfonts
PKGNAME=	tex-${DISTNAME}-2019.51356
PKGREVISION=	1
TEXLIVE_REV=	51356

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/sansmathfonts
COMMENT=	Correct placement of accents in sans-serif maths
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	sansmathfonts.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
