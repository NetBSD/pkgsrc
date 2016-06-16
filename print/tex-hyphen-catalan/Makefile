# $NetBSD: Makefile,v 1.6 2016/06/16 04:06:05 markd Exp $

DISTNAME=	hyphen-catalan
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Catalan
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	catalan loadhyph-ca.tex
TEX_HYPHEN_DEF+=	\\addlanguage{catalan}{loadhyph-ca.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['catalan']={ \
			  loader='loadhyph-ca.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-ca.pat.txt', \
			  hyphenation='hyph-ca.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
