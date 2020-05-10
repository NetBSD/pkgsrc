# $NetBSD: Makefile,v 1.6 2020/05/10 04:31:52 markd Exp $

DISTNAME=	raleway
PKGNAME=	tex-${DISTNAME}-1.4
PKGREVISION=	1
TEXLIVE_REV=	42629

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/raleway
COMMENT=	Use Raleway with TeX(-alike) systems
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	Raleway.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
