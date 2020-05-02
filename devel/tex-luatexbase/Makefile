# $NetBSD: Makefile,v 1.8 2020/05/02 03:01:51 markd Exp $

DISTNAME=	luatexbase
PKGNAME=	tex-${DISTNAME}-1.3
PKGREVISION=	2
TEXLIVE_REV=	38550

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Basic resource management for LuaTeX code
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ctablestack-[0-9]*:../../print/tex-ctablestack
DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
