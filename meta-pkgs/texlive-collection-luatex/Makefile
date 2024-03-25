# $NetBSD: Makefile,v 1.28 2024/03/25 11:09:09 markd Exp $

DISTNAME=	collection-luatex
PKGNAME=	texlive-${DISTNAME}-2024pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	70711

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	LuaTeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend addliga
# depend addtoluatexpath
# depend auto-pst-pdf-lua
# depend barracuda
# depend bezierplot
# depend blopentype
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
# depend gitinfo-lua
# depend ideavault
# depend innerscript
# depend interpreter
# depend kanaparser
# depend ligtype
# depend linebreaker
# depend lparse
# depend lt3luabridge
# depend lua-placeholders
# depend lua-tinyyaml
# depend lua-typo
# depend lua-uca
DEPENDS+=	tex-lua-ul-[0-9]*:../../print/tex-lua-ul
DEPENDS+=	tex-lua-uni-algos-[0-9]*:../../print/tex-lua-uni-algos
# depend lua-visual-debug
# depend lua-widow-control
# depend luaaddplot
# depend luacas
# depend luacensor
DEPENDS+=	tex-luacode-[0-9]*:../../print/tex-luacode
DEPENDS+=	tex-luacolor-[0-9]*:../../print/tex-luacolor
# depend luacomplex
# depend luagcd
# depend luahttp
# depend luahyphenrules
# depend luaimageembed
# depend luaindex
# depend luainputenc
# depend luakeys
DEPENDS+=	tex-lualatex-math-[0-9]*:../../math/tex-lualatex-math
# depend lualatex-truncate
DEPENDS+=	tex-lualibs-[0-9]*:../../devel/tex-lualibs
# depend lualinalg
# depend luamathalign
# depend luamaths
# depend luamodulartables
# depend luamplib
# depend luaoptions
DEPENDS+=	tex-luaotfload-[0-9]*:../../fonts/tex-luaotfload
# depend luapackageloader
# depend luaplot
# depend luaprogtable
# depend luaquotes
# depend luaset
# depend luarandom
DEPENDS+=	tex-luatex85-[0-9]*:../../print/tex-luatex85
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase
# depend luatexko
# depend luatextra
# depend luatruthtable
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
# depend penlightplus
# depend piton
# depend placeat
# depend plantuml
# depend pyluatex
# depend scikgtex
# depend selnolig
# depend showhyphenation
# depend showkerning
# depend spacekern
# depend spelling
# depend stricttex
# depend sympycalc
# depend texfindpkg
# depend truthtable
# depend tsvtemplate
# depend typewriter
# depend uninormalize
# depend yamlvars

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
