# $NetBSD: Makefile,v 1.4 2010/11/10 17:55:35 minskim Exp $

DISTNAME=	hyphen-swedish
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Swedish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	swedish loadhyph-sv.tex
TEX_HYPHEN_DEF+=	\addlanguage{swedish}{loadhyph-sv.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['swedish']={ \
			  loader='loadhyph-sv.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-sv.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
