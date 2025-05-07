# $NetBSD: Makefile,v 1.13 2025/05/07 11:44:18 markd Exp $

DISTNAME=	hyphen-arabic
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	74115

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Arabic
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	arabic hyph-ar.tex
TEX_HYPHEN_DEF+=	\\addlanguage{arabic}{hyph-ar.tex}{}{0}{0}
TEX_HYPHEN_LUA+=	['arabic']={ \
			  loader='hyph-ar.tex', \
			  lefthyphenmin=0, \
			  righthyphenmin=0, \
			  synonyms={}, \
			  patterns='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
