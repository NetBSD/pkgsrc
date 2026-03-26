# $NetBSD: Makefile,v 1.15 2026/03/26 08:07:46 markd Exp $

DISTNAME=	hyphen-polish
PKGNAME=	tex-${DISTNAME}-3.0b.2026
TEXLIVE_REV=	78069

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation for Polish
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

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
