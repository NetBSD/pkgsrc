# $NetBSD: Makefile,v 1.3 2019/12/06 19:29:38 markd Exp $

DISTNAME=	bookhands
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	46480

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/bookhands
COMMENT=	Collection of book-hand fonts
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	sqrcaps.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
