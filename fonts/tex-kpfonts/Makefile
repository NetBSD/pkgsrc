# $NetBSD: Makefile,v 1.4 2020/01/18 23:31:39 rillig Exp $

DISTNAME=	kpfonts
PKGNAME=	tex-${DISTNAME}-3.33
TEXLIVE_REV=	48470

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/kpfonts
COMMENT=	Complete set of fonts for text and mathematics
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	kpfonts.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
