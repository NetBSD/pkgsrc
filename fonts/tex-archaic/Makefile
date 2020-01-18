# $NetBSD: Makefile,v 1.4 2020/01/18 23:31:10 rillig Exp $

DISTNAME=	archaic
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	38005

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/archaic
COMMENT=	Collection of archaic fonts
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	archaicprw.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
