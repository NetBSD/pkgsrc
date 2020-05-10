# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:48 markd Exp $

DISTNAME=	lobster2
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	32617

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lobster2
COMMENT=	Lobster Two fonts, with support for all LaTeX engines
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	LobsterTwo.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
