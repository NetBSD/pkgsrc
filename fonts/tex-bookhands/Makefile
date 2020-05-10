# $NetBSD: Makefile,v 1.5 2020/05/10 04:31:39 markd Exp $

DISTNAME=	bookhands
PKGNAME=	tex-${DISTNAME}-2018
PKGREVISION=	1
TEXLIVE_REV=	46480

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bookhands
COMMENT=	Collection of book-hand fonts
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	sqrcaps.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
