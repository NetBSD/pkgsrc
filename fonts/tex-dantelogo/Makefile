# $NetBSD: Makefile,v 1.4 2020/01/18 23:31:23 rillig Exp $

DISTNAME=	dantelogo
PKGNAME=	tex-${DISTNAME}-0.03
TEXLIVE_REV=	38599

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dantelogo
COMMENT=	Font for DANTE's logo
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	dante.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
