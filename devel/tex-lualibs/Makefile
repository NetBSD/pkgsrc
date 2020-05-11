# $NetBSD: Makefile,v 1.11 2020/05/11 10:52:57 markd Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.71
TEXLIVE_REV=	54994

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
