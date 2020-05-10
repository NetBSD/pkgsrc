# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:37 markd Exp $

DISTNAME=	antiqua
PKGNAME=	tex-${DISTNAME}-001.003
PKGREVISION=	1
TEXLIVE_REV=	24266

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/urw-antiqua
COMMENT=	URW Antiqua condensed font, for use with TeX
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	uaq.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
