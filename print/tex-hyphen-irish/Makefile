# $NetBSD: Makefile,v 1.3 2010/11/08 16:44:52 minskim Exp $

DISTNAME=	hyphen-irish
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Irish

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	irish loadhyph-ga.tex
TEX_HYPHEN_DEF+=	\addlanguage{irish}{loadhyph-ga.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['irish']={ \
			\\tloader='loadhyph-ga.tex', \
			\\tlefthyphenmin=2, \
			\\trighthyphenmin=3, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-ga.pat.txt', \
			\\thyphenation='hyph-ga.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
