# $NetBSD: Makefile,v 1.5 2020/05/10 04:31:37 markd Exp $

DISTNAME=	archaic
PKGNAME=	tex-${DISTNAME}-2015
PKGREVISION=	1
TEXLIVE_REV=	38005

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/archaic
COMMENT=	Collection of archaic fonts
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	archaicprw.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
