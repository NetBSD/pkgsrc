# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:56 rillig Exp $

DISTNAME=	universalis
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	33860

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/universalis
COMMENT=	Universalis font, with support
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	universalis.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
