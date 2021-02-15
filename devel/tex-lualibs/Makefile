# $NetBSD: Makefile,v 1.12 2021/02/15 00:25:23 markd Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.73
TEXLIVE_REV=	57277

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
