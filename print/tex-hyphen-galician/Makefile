# $NetBSD: Makefile,v 1.14 2026/03/26 08:07:43 markd Exp $

DISTNAME=	hyphen-galician
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78069

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Galician
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	galician loadhyph-gl.tex
TEX_HYPHEN_DEF+=	\\addlanguage{galician}{loadhyph-gl.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['galician']={ \
			  loader='loadhyph-gl.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-gl.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
