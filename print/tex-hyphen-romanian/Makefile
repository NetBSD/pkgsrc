# $NetBSD: Makefile,v 1.7 2017/09/06 16:49:38 wiz Exp $

DISTNAME=	hyphen-romanian
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Romanian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	romanian loadhyph-ro.tex
TEX_HYPHEN_DEF+=	\\addlanguage{romanian}{loadhyph-ro.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['romanian']={ \
			  loader='loadhyph-ro.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-ro.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
