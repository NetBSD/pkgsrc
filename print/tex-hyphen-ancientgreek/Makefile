# $NetBSD: Makefile,v 1.16 2021/05/30 08:04:41 markd Exp $

DISTNAME=	hyphen-ancientgreek
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for ancient Greek
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	ancientgreek loadhyph-grc.tex
TEX_HYPHEN_DAT+=	ibycus ibyhyph.tex
TEX_HYPHEN_DEF+=	\\addlanguage{ancientgreek}{loadhyph-grc.tex}{}{1}{1}
TEX_HYPHEN_DEF+=	\\addlanguage{ibycus}{ibyhyph.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['ancientgreek']={ \
			  loader='loadhyph-grc.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-grc.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_LUA+=	['ibycus']={ \
			  loader='ibyhyph.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  special='disabled:8-bit+only', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
