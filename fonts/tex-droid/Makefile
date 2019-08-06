# $NetBSD: Makefile,v 1.2 2019/08/06 11:09:16 markd Exp $

DISTNAME=	droid
PKGNAME=	tex-${DISTNAME}-3.2
TEXLIVE_REV=	51468

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/droid
COMMENT=	LaTeX support for the Droid font families
LICENSE=	apache-2.0 AND lppl-1.3c

TEX_MAP_FILES+=	droidsans.map
TEX_MAP_FILES+=	droidsansmono.map
TEX_MAP_FILES+=	droidserif.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
