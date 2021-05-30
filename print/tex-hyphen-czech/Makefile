# $NetBSD: Makefile,v 1.13 2021/05/30 08:04:43 markd Exp $

DISTNAME=	hyphen-czech
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58609

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Czech
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	czech loadhyph-cs.tex
TEX_HYPHEN_DEF+=	\\addlanguage{czech}{loadhyph-cs.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['czech']={ \
			  loader='loadhyph-cs.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='hyph-cs.pat.txt', \
			  hyphenation='hyph-cs.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
