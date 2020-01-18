# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:48 rillig Exp $

DISTNAME=	playfair
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	34236

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/playfair
COMMENT=	Playfair Display fonts with LaTeX support
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	PlayfairDisplay.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
