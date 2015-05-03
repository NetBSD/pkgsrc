# $NetBSD: Makefile,v 1.5 2015/05/03 17:52:41 wiz Exp $

DISTNAME=	hyphen-slovak
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	2
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Slovak

CONFLICTS+=	teTeX-texmf<=3.0nb12
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
