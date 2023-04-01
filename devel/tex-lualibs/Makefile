# $NetBSD: Makefile,v 1.14 2023/04/01 11:53:53 markd Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.75
TEXLIVE_REV=	64615

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
