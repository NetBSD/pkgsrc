# $NetBSD: Makefile,v 1.7 2017/09/06 16:49:35 wiz Exp $

DISTNAME=	hyphen-bulgarian
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	41113

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Bulgarian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	bulgarian loadhyph-bg.tex
TEX_HYPHEN_DEF+=	\\addlanguage{bulgarian}{loadhyph-bg.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['bulgarian']={ \
			  loader='loadhyph-bg.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-bg.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
