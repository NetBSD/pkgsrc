# $NetBSD: Makefile,v 1.2 2019/12/06 19:32:26 markd Exp $

DISTNAME=	staves
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/staves
COMMENT=	Typeset Icelandic staves and runic letters
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	icelandic.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
