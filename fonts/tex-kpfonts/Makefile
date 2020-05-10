# $NetBSD: Makefile,v 1.5 2020/05/10 04:31:47 markd Exp $

DISTNAME=	kpfonts
PKGNAME=	tex-${DISTNAME}-3.33
PKGREVISION=	1
TEXLIVE_REV=	48470

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/kpfonts
COMMENT=	Complete set of fonts for text and mathematics
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	kpfonts.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
