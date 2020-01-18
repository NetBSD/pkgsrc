# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:35 rillig Exp $

DISTNAME=	gillius
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	32068

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/gillius
COMMENT=	Gillius fonts with LaTeX support
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	gillius.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
