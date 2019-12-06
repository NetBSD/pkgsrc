# $NetBSD: Makefile,v 1.3 2019/12/06 19:29:31 markd Exp $

DISTNAME=	allrunes
PKGNAME=	tex-${DISTNAME}-2.1.1
TEXLIVE_REV=	42221

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/allrunes
COMMENT=	Fonts and LaTeX package for almost all runes
LICENSE=	lppl-1.3c

TEX_MIXEDMAP_FILES+=	allrunes.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
