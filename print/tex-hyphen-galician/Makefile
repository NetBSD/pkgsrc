# $NetBSD: Makefile,v 1.3 2010/11/08 16:44:39 minskim Exp $

DISTNAME=	hyphen-galician
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Galician

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	galician loadhyph-gl.tex
TEX_HYPHEN_DEF+=	\addlanguage{galician}{loadhyph-gl.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['galician']={ \
			\\tloader='loadhyph-gl.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=2, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-gl.pat.txt', \
			\\thyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
