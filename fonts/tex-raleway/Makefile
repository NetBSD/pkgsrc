# $NetBSD: Makefile,v 1.5 2020/01/18 23:31:50 rillig Exp $

DISTNAME=	raleway
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	42629

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/raleway
COMMENT=	Use Raleway with TeX(-alike) systems
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	Raleway.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
