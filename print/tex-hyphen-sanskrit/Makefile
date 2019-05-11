# $NetBSD: Makefile,v 1.9 2019/05/11 06:57:27 markd Exp $

DISTNAME=	hyphen-sanskrit
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50792

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Sanskrit
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	sanskrit loadhyph-sa.tex
TEX_HYPHEN_DEF+=	\\addlanguage{sanskrit}{loadhyph-sa.tex}{}{1}{3}
TEX_HYPHEN_LUA+=	['sanskrit']={ \
			  loader='loadhyph-sa.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='hyph-sa.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
