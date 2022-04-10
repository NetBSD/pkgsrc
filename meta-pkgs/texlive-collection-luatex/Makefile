# $NetBSD: Makefile,v 1.17 2022/04/10 03:28:05 markd Exp $

DISTNAME=	collection-luatex
PKGNAME=	texlive-${DISTNAME}-2021pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	62829

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
# depend chinese-jfm
# depend cloze
# depend combofont
# depend cstypo
DEPENDS+=	tex-ctablestack-[0-9]*:../../print/tex-ctablestack
# depend ekdosis
# depend emoji
# depend emojicite
# depend enigma
# depend innerscript
# depend interpreter
# depend kanaparser
# depend linebreaker
# depend lua-typo
# depend lua-uca
# depend lua-ul
# depend lua-uni-algos
# depend lua-visual-debug
# depend lua-widow-control
# depend luaaddplot
# depend luacensor
DEPENDS+=	tex-luacode-[0-9]*:../../print/tex-luacode
DEPENDS+=	tex-luacolor-[0-9]*:../../print/tex-luacolor
# depend luahyphenrules
# depend luaimageembed
# depend luaindex
# depend luainputenc
# depend luaintro
# depend luakeys
# depend lualatex-doc
DEPENDS+=	tex-lualatex-math-[0-9]*:../../math/tex-lualatex-math
# depend lualatex-truncate
DEPENDS+=	tex-lualibs-[0-9]*:../../devel/tex-lualibs
# depend luamplib
DEPENDS+=	tex-luaotfload-[0-9]*:../../fonts/tex-luaotfload
# depend luapackageloader
# depend luaprogtable
# depend luarandom
DEPENDS+=	tex-luatex85-[0-9]*:../../print/tex-luatex85
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase
# depend luatexko
# depend luatextra
# depend luavlna
# depend luaxml
# depend lutabulartools
# depend minim
# depend minim-math
# depend minim-mp
# depend minim-pdf
# depend minim-xmp
# depend newpax
# depend nodetree
# depend odsfile
# depend optex
# depend pdfarticle
# depend pdfextra
# depend penlight
# depend placeat
# depend plantuml
# depend pyluatex
# depend selnolig
# depend spelling
# depend stricttex
# depend truthtable
# depend typewriter
# depend uninormalize
# depend yamlvars

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
