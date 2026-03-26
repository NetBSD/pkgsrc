# $NetBSD: Makefile,v 1.15 2026/03/26 08:07:44 markd Exp $

DISTNAME=	hyphen-irish
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78069

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Irish
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	irish loadhyph-ga.tex
TEX_HYPHEN_DEF+=	\\addlanguage{irish}{loadhyph-ga.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['irish']={ \
			  loader='loadhyph-ga.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='hyph-ga.pat.txt', \
			  hyphenation='hyph-ga.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
