# $NetBSD: Makefile,v 1.6 2020/05/10 04:31:57 markd Exp $

DISTNAME=	arabtex
PKGNAME=	tex-${DISTNAME}-3.17
PKGREVISION=	1
TEXLIVE_REV=	25711

MAINTAINER=	kamelderouiche@yahoo.com
COMMENT=	Macros and fonts for typesetting Arabic
LICENSE=	lppl-1.3c

TEX_MIXEDMAP_FILES+=	arabtex.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
