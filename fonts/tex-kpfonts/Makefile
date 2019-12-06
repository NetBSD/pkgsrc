# $NetBSD: Makefile,v 1.3 2019/12/06 19:30:09 markd Exp $

DISTNAME=	kpfonts
PKGNAME=	tex-${DISTNAME}-3.33
TEXLIVE_REV=	48470

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/kpfonts
COMMENT=	Complete set of fonts for text and mathematics
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	kpfonts.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
