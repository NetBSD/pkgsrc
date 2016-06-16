# $NetBSD: Makefile,v 1.5 2016/06/16 03:54:44 markd Exp $

DISTNAME=	luatexbase
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	38550

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Basic resource management for LuaTeX code
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
