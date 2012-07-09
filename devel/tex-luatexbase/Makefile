# $NetBSD: Makefile,v 1.1 2012/07/09 14:05:52 minskim Exp $

DISTNAME=	luatexbase
PKGNAME=	tex-${DISTNAME}-0.31
TEXLIVE_REV=	22560

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Basic resource management for LuaTeX code

DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-luatex-[0-9]*:../../print/luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
