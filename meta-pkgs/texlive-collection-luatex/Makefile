# $NetBSD: Makefile,v 1.3 2016/06/16 04:03:15 markd Exp $

DISTNAME=	collection-luatex
PKGNAME=	texlive-${DISTNAME}-2016pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	39902

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	LuaTeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend checkcites
# depend chickenize
# depend cloze
# depend ctablestack
# depend enigma
# depend interpreter
# depend lua-check-hyphen
# depend lua-visual-debug
# depend lua2dox
# depend luabibentry
# depend luabidi
# depend luacode
# depend luaindex
# depend luainputenc
# depend luaintro
# depend lualatex-doc
# depend lualatex-math
DEPENDS+=	tex-lualibs-[0-9]*:../../devel/tex-lualibs
# depend luamplib
DEPENDS+=	tex-luaotfload-[0-9]*:../../fonts/tex-luaotfload
# depend luasseq
# depend luatex-def
# depend luatex85
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase
# depend luatexko
# depend luatextra
# depend luatodonotes
# depend luaxml
# depend odsfile
# depend placeat
# depend selnolig
# depend showhyphens
# depend spelling
# depend ucharcat

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
