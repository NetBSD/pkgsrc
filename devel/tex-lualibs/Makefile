# $NetBSD: Makefile,v 1.10 2020/04/27 03:26:39 markd Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.70
TEXLIVE_REV=	53682

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
