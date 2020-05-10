# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:37 markd Exp $

DISTNAME=	aramaic-serto
PKGNAME=	tex-${DISTNAME}-1.0
PKGREVISION=	1
TEXLIVE_REV=	30042

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/aramaic-serto
COMMENT=	Fonts and LaTeX for Syriac written in Serto
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	syriac.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
