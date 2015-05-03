# $NetBSD: Makefile,v 1.6 2015/05/03 17:52:41 wiz Exp $

DISTNAME=	hyphen-uppersorbian
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	2
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Upper Sorbian

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	uppersorbian loadhyph-hsb.tex
TEX_HYPHEN_DEF+=	\\addlanguage{uppersorbian}{loadhyph-hsb.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['uppersorbian']={ \
			  loader='loadhyph-hsb.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-hsb.pat.txt', \
			  hyphenation='hyph-hsb.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
