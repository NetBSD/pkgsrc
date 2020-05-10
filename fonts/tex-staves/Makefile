# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:54 markd Exp $

DISTNAME=	staves
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/staves
COMMENT=	Typeset Icelandic staves and runic letters
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	icelandic.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
