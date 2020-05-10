# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:55 markd Exp $

DISTNAME=	venturisadf
PKGNAME=	tex-${DISTNAME}-1.005
PKGREVISION=	1
TEXLIVE_REV=	19444

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/venturisadf
COMMENT=	Venturis ADF fonts collection
#LICENSE=	other-free

TEX_MAP_FILES+=	yv1.map
TEX_MAP_FILES+=	yv2.map
TEX_MAP_FILES+=	yv3.map
TEX_MAP_FILES+=	yvo.map
TEX_MAP_FILES+=	yvt.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
