# $NetBSD: Makefile,v 1.3 2015/04/21 23:26:35 markd Exp $

DISTNAME=	luatexbase
PKGNAME=	tex-${DISTNAME}-0.6
TEXLIVE_REV=	30562

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Basic resource management for LuaTeX code

DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
