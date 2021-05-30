# $NetBSD: Makefile,v 1.13 2021/05/30 08:04:44 markd Exp $

DISTNAME=	hyphen-finnish
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Finnish language
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	finnish loadhyph-fi.tex
TEX_HYPHEN_DEF+=	\\addlanguage{finnish}{loadhyph-fi.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['finnish']={ \
			  loader='loadhyph-fi.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-fi.pat.txt', \
			  hyphenation='', \
			},

TEX_HYPHEN_DAT+=	schoolfinnish loadhyph-fi-x-school.tex
TEX_HYPHEN_DEF+=	\\addlanguage{schoolfinnish}{loadhyph-fi-x-school.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['schoolfinnish']={ \
			  loader='loadhyph-fi-x-school.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-fi-x-school.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
