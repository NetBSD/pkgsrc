# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:53 rillig Exp $

DISTNAME=	staves
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/staves
COMMENT=	Typeset Icelandic staves and runic letters
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	icelandic.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
