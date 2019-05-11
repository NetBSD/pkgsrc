# $NetBSD: Makefile,v 1.9 2019/05/11 06:57:23 markd Exp $

DISTNAME=	hyphen-arabic
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50805

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Arabic
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	arabic zerohyph.tex
TEX_HYPHEN_DEF+=	\\addlanguage{arabic}{zerohyph.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['arabic']={ \
			  loader='zerohyph.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
