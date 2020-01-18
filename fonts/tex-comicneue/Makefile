# $NetBSD: Makefile,v 1.4 2020/01/18 23:31:21 rillig Exp $

DISTNAME=	comicneue
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	42851

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/comicneue
COMMENT=	Use Comic Neue with TeX(-alike) systems
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	ComicNeue.map
TEX_MAP_FILES+=	ComicNeueAngular.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
