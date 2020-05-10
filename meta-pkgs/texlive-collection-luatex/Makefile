# $NetBSD: Makefile,v 1.13 2020/05/10 04:13:27 markd Exp $

DISTNAME=	collection-luatex
PKGNAME=	texlive-${DISTNAME}-2020pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	54741

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	LuaTeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend addliga
# depend auto-pst-pdf-lua
# depend barracuda
# depend bezierplot
# depend checkcites
# depend chickenize
# depend combofont
# depend cstypo
DEPENDS+=	tex-ctablestack-[0-9]*:../../print/tex-ctablestack
# depend emoji
# depend emojicite
# depend enigma
# depend interpreter
# depend kanaparser
# depend lua-uca
# depend lua-ul
# depend lua-visual-debug
DEPENDS+=	tex-luacode-[0-9]*:../../print/tex-luacode
DEPENDS+=	tex-luacolor-[0-9]*:../../print/tex-luacolor
# depend luahyphenrules
# depend luaimageembed
# depend luaindex
# depend luainputenc
# depend luaintro
# depend lualatex-doc
# depend lualatex-math
# depend lualatex-truncate
DEPENDS+=	tex-lualibs-[0-9]*:../../devel/tex-lualibs
# depend luamplib
DEPENDS+=	tex-luaotfload-[0-9]*:../../fonts/tex-luaotfload
# depend luapackageloader
# depend luarandom
DEPENDS+=	tex-luatex85-[0-9]*:../../print/tex-luatex85
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase
# depend luatexko
# depend luatextra
# depend luavlna
# depend luaxml
# depend nodetree
# depend odsfile
# depend optex
# depend pdfarticle
# depend placeat
# depend plantuml
# depend selnolig
# depend spelling
# depend typewriter

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
