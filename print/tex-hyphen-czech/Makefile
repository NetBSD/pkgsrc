# $NetBSD: Makefile,v 1.10 2019/08/04 12:13:52 markd Exp $

DISTNAME=	hyphen-czech
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Czech
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

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
