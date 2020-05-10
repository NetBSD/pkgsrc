# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:48 markd Exp $

DISTNAME=	libris
PKGNAME=	tex-${DISTNAME}-1.007
PKGREVISION=	1
TEXLIVE_REV=	19409

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/libris
COMMENT=	Libris ADF fonts, with LaTeX support
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	yly.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
