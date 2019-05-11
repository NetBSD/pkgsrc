# $NetBSD: Makefile,v 1.9 2019/05/11 06:57:24 markd Exp $

DISTNAME=	hyphen-dutch
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50792

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Dutch
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	dutch loadhyph-nl.tex
TEX_HYPHEN_DEF+=	\\addlanguage{dutch}{loadhyph-nl.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['dutch']={ \
			  loader='loadhyph-nl.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-nl.pat.txt', \
			  hyphenation='hyph-nl.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
