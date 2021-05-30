# $NetBSD: Makefile,v 1.13 2021/05/30 08:04:47 markd Exp $

DISTNAME=	hyphen-slovak
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58609

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Slovak
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

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
