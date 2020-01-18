# $NetBSD: Makefile,v 1.4 2020/01/18 23:31:50 rillig Exp $

DISTNAME=	quattrocento
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50729

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/quattrocento
COMMENT=	LaTeX support for Quattrocento and Quattrocento Sans fonts
LICENSE=	ofl-v1.1 AND lppl-1.3c

TEX_MAP_FILES+=	quattrocento.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
