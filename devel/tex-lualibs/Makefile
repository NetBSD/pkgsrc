# $NetBSD: Makefile,v 1.6 2019/05/07 12:32:55 markd Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.64
TEXLIVE_REV=	50130

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
