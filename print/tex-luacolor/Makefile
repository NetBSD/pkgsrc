# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:41 markd Exp $

DISTNAME=	luacolor
PKGNAME=	tex-${DISTNAME}-1.15
TEXLIVE_REV=	53933

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luacolor
COMMENT=	Color support based on LuaTeX's node attributes
LICENSE=	lppl-1.3c

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
