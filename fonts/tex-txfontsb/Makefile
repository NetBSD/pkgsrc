# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:55 rillig Exp $

DISTNAME=	txfontsb
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	21578

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/txfontsb
COMMENT=	Extensions to txfonts, using GNU Freefont
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	gptimes.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
