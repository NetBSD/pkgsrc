# $NetBSD: Makefile,v 1.2 2019/12/06 19:30:11 markd Exp $

DISTNAME=	libris
PKGNAME=	tex-${DISTNAME}-1.007
TEXLIVE_REV=	19409

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/libris
COMMENT=	Libris ADF fonts, with LaTeX support
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	yly.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
