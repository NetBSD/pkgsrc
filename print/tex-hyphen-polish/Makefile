# $NetBSD: Makefile,v 1.5 2015/05/03 17:52:41 wiz Exp $

DISTNAME=	hyphen-polish
PKGNAME=	tex-${DISTNAME}-3.0a
PKGREVISION=	2
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation for Polish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	polish loadhyph-pl.tex
TEX_HYPHEN_DEF+=	\\addlanguage{polish}{loadhyph-pl.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['polish']={ \
			  loader='loadhyph-pl.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-pl.pat.txt', \
			  hyphenation='hyph-pl.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
