# $NetBSD: Makefile,v 1.2 2015/05/08 22:24:40 markd Exp $

DISTNAME=	mathabx-type1
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	21129

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/mathabx-type1
COMMENT=	Outline version of the mathabx fonts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-mathabx-[0-9]*:../../fonts/tex-mathabx

TEX_MAP_FILES+=	mathabx.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
