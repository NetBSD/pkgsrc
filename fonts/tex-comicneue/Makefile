# $NetBSD: Makefile,v 1.3 2019/12/06 19:29:46 markd Exp $

DISTNAME=	comicneue
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	42851

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/comicneue
COMMENT=	Use Comic Neue with TeX(-alike) systems
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	ComicNeue.map
TEX_MAP_FILES+=	ComicNeueAngular.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
