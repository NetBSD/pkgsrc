# $NetBSD: Makefile,v 1.5 2020/05/10 04:31:45 markd Exp $

DISTNAME=	gentium-tug
PKGNAME=	tex-${DISTNAME}-1.1.1
PKGREVISION=	1
TEXLIVE_REV=	51613

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/gentium-tug
COMMENT=	Gentium fonts (in two formats) and support files
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	gentium-type1.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
