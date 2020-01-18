# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:09 rillig Exp $

DISTNAME=	antiqua
PKGNAME=	tex-${DISTNAME}-001.003
TEXLIVE_REV=	24266

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/urw-antiqua
COMMENT=	URW Antiqua condensed font, for use with TeX
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	uaq.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
