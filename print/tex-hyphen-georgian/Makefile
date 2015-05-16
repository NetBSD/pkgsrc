# $NetBSD: Makefile,v 1.1 2015/05/16 02:51:23 markd Exp $

DISTNAME=	hyphen-georgian
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	30326

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Georgian hyphenation patterns

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	georgian loadhyph-ka.tex
TEX_HYPHEN_DEF+=	\\addlanguage{georgian}{loadhyph-ka.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['georgian']={ \
			  loader='loadhyph-ka.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='hyph-ka.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
