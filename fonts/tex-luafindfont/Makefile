# $NetBSD: Makefile,v 1.1 2022/04/16 00:52:11 markd Exp $

DISTNAME=	luafindfont
PKGNAME=	tex-${DISTNAME}-0.06
TEXLIVE_REV=	61959

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luafindfont
COMMENT=	Search fonts in the LuaTeX font database
LICENSE=	lppl-1.3c

DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex

REPLACE_TEXLUA=	texmf-dist/scripts/luafindfont/luafindfont.lua

INSTALLATION_DIRS+=	bin

post-install:
	ln -s ${PREFIX}/share/texmf-dist/scripts/luafindfont/luafindfont.lua ${DESTDIR}${PREFIX}/bin/luafindfont

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
