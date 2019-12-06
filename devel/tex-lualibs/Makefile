# $NetBSD: Makefile,v 1.8 2019/12/06 19:18:35 markd Exp $

DISTNAME=	lualibs
PKGNAME=	tex-${DISTNAME}-2.66
TEXLIVE_REV=	51642

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/lualibs
COMMENT=	Additional Lua functions for LuaTeX macro programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex-[0-9]*:../../print/luatex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
