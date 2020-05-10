# $NetBSD: Makefile,v 1.5 2020/05/10 04:31:42 markd Exp $

DISTNAME=	dantelogo
PKGNAME=	tex-${DISTNAME}-0.03
PKGREVISION=	1
TEXLIVE_REV=	38599

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dantelogo
COMMENT=	Font for DANTE's logo
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	dante.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
