# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:40 rillig Exp $

DISTNAME=	libris
PKGNAME=	tex-${DISTNAME}-1.007
TEXLIVE_REV=	19409

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/libris
COMMENT=	Libris ADF fonts, with LaTeX support
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	yly.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
