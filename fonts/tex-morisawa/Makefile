# $NetBSD: Makefile,v 1.1 2021/02/21 08:48:23 markd Exp $

DISTNAME=	morisawa
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	46946

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/morisawa
COMMENT=	Enables selection of 5 standard Japanese fonts for pLaTeX + dvips
LICENSE=	modified-bsd

TEX_KANJIMAP_FILES+=	morisawa5.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
