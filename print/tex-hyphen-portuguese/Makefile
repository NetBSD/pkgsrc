# $NetBSD: Makefile,v 1.4 2010/11/10 17:55:34 minskim Exp $

DISTNAME=	hyphen-portuguese
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Portuguese

CONFLICTS+=	teTeX-texmf<=3.0nb24
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	portuguese loadhyph-pt.tex
TEX_HYPHEN_DAT+=	= portuges
TEX_HYPHEN_DEF+=	\addlanguage{portuguese}{loadhyph-pt.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\addlanguage{portuges}{loadhyph-pt.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['portuguese']={ \
			  loader='loadhyph-pt.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={'portuges',}, \
			  patterns='hyph-pt.pat.txt', \
			  hyphenation='hyph-pt.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
