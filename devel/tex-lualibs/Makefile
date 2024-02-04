# $NetBSD: Makefile,v 1.15 2024/02/04 10:39:11 markd Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.76
TEXLIVE_REV=	67994

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
