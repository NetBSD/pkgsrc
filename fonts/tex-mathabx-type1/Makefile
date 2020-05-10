# $NetBSD: Makefile,v 1.5 2020/05/10 04:31:49 markd Exp $

DISTNAME=	mathabx-type1
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	21129

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathabx-type1
COMMENT=	Outline version of the mathabx fonts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-mathabx-[0-9]*:../../fonts/tex-mathabx

TEX_MAP_FILES+=	mathabx.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
