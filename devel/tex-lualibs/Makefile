# $NetBSD: Makefile,v 1.13 2021/06/06 11:01:49 markd Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.74
TEXLIVE_REV=	59298

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
