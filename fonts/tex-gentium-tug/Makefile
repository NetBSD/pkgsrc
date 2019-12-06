# $NetBSD: Makefile,v 1.4 2019/12/06 19:30:02 markd Exp $

DISTNAME=	gentium-tug
PKGNAME=	tex-${DISTNAME}-1.1.1
TEXLIVE_REV=	51613

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/gentium-tug
COMMENT=	Gentium fonts (in two formats) and support files
LICENSE=	ofl-v1.1

TEX_MAP_FILES+=	gentium-type1.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
