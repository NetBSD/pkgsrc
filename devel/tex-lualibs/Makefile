# $NetBSD: Makefile,v 1.5 2019/01/30 10:23:19 markd Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.62
TEXLIVE_REV=	49741

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
