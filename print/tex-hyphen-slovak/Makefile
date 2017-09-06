# $NetBSD: Makefile,v 1.7 2017/09/06 16:49:38 wiz Exp $

DISTNAME=	hyphen-slovak
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Slovak
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	slovak loadhyph-sk.tex
TEX_HYPHEN_DEF+=	\\addlanguage{slovak}{loadhyph-sk.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['slovak']={ \
			  loader='loadhyph-sk.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='hyph-sk.pat.txt', \
			  hyphenation='hyph-sk.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
