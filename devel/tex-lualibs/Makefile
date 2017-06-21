# $NetBSD: Makefile,v 1.4 2017/06/21 08:28:42 markd Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.5
TEXLIVE_REV=	43153

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
