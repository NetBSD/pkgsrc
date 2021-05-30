# $NetBSD: Makefile,v 1.14 2021/05/30 08:04:45 markd Exp $

DISTNAME=	hyphen-hungarian
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	minskim@NetBSD.org
COMMENT=	New Hungarian hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	hungarian loadhyph-hu.tex
TEX_HYPHEN_DEF+=	\\addlanguage{hungarian}{loadhyph-hu.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['hungarian']={ \
			  loader='loadhyph-hu.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-hu.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
