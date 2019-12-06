# $NetBSD: Makefile,v 1.3 2019/12/06 19:30:15 markd Exp $

DISTNAME=	merriweather
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	51304

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/merriweather
COMMENT=	Merriweather and MerriweatherSans fonts, with LaTeX support
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	merriweather.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
