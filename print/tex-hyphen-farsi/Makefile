# $NetBSD: Makefile,v 1.10 2019/12/06 20:21:37 markd Exp $

DISTNAME=	hyphen-farsi
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50805

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Farsi
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	farsi zerohyph.tex
TEX_HYPHEN_DAT+=	= persian
TEX_HYPHEN_DEF+=	\\addlanguage{farsi}{zerohyph.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\\addlanguage{persian}{zerohyph.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['farsi']={ \
			  loader='zerohyph.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={'persian',}, \
			  patterns='', \
			},

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
