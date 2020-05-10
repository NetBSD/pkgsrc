# $NetBSD: Makefile,v 1.6 2020/05/10 04:31:53 markd Exp $

DISTNAME=	sourcesanspro
PKGNAME=	tex-${DISTNAME}-2.6
PKGREVISION=	1
TEXLIVE_REV=	42852

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/sourcesanspro
COMMENT=	Use SourceSansPro with TeX(-alike) systems
LICENSE=	ofl-v1.1 AND lppl-1.3c

TEX_MAP_FILES+=	SourceSansPro.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
