# $NetBSD: Makefile,v 1.7 2019/08/11 05:36:12 markd Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.66
TEXLIVE_REV=	51642

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
