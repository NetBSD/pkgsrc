# $NetBSD: Makefile,v 1.1 2015/05/16 02:51:23 markd Exp $

DISTNAME=	hyphen-thai
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	30605

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Thai hyphenation patterns

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	thai loadhyph-th.tex
TEX_HYPHEN_DEF+=	\\addlanguage{thai}{loadhyph-th.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['thai']={ \
			  loader='loadhyph-th.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='hyph-th.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
