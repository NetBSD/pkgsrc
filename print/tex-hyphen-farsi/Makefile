# $NetBSD: Makefile,v 1.13 2025/05/07 11:44:20 markd Exp $

DISTNAME=	hyphen-farsi
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	74115

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Farsi
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	farsi hyph-fa.tex
TEX_HYPHEN_DAT+=	= persian
TEX_HYPHEN_DEF+=	\\addlanguage{farsi}{hyph-fa.tex}{}{0}{0}
TEX_HYPHEN_DEF+=	\\addlanguage{persian}{hyph-fa.tex}{}{0}{0}
TEX_HYPHEN_LUA+=	['farsi']={ \
			  loader='hyph-fa.tex', \
			  lefthyphenmin=0, \
			  righthyphenmin=0, \
			  synonyms={'persian',}, \
			  patterns='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
