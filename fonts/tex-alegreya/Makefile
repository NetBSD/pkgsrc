# $NetBSD: Makefile,v 1.8 2020/01/18 23:31:08 rillig Exp $

DISTNAME=	alegreya
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50277

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/alegreya
COMMENT=	Alegreya fonts with LaTeX support
LICENSE=	ofl-v1.1 AND lppl-1.3c

TEX_MAP_FILES+=	Alegreya.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
