# $NetBSD: Makefile,v 1.4 2010/11/08 17:00:52 minskim Exp $

DISTNAME=	hyphen-coptic
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20144

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Coptic

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	coptic loadhyph-cop.tex
TEX_HYPHEN_DEF+=	\addlanguage{coptic}{loadhyph-cop.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['coptic']={ \
			\\tloader='loadhyph-cop.tex', \
			\\tlefthyphenmin=1, \
			\\trighthyphenmin=1, \
			\\tsynonyms={}, \
			\\tpatterns='hyph-cop.pat.txt', \
			\\thyphenation='', \
			},
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
