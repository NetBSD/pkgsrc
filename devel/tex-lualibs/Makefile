# $NetBSD: Makefile,v 1.9 2020/01/18 23:30:43 rillig Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.66
TEXLIVE_REV=	51642

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
