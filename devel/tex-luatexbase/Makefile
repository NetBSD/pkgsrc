# $NetBSD: Makefile,v 1.2 2012/11/18 01:08:35 dholland Exp $

DISTNAME=	luatexbase
PKGNAME=	tex-${DISTNAME}-0.31
TEXLIVE_REV=	22560
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Basic resource management for LuaTeX code

DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
