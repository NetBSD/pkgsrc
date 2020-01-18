# $NetBSD: Makefile,v 1.7 2020/01/18 23:31:16 rillig Exp $

DISTNAME=	cabin
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50936

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cabin
COMMENT=	Humanist Sans Serif font, with LaTeX support
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	cabin.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
