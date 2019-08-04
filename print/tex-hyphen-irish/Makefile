# $NetBSD: Makefile,v 1.10 2019/08/04 19:53:45 markd Exp $

DISTNAME=	hyphen-irish
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Irish
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

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
