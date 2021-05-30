# $NetBSD: Makefile,v 1.13 2021/05/30 08:04:44 markd Exp $

DISTNAME=	hyphen-esperanto
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Esperanto
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	esperanto loadhyph-eo.tex
TEX_HYPHEN_DEF+=	\\addlanguage{esperanto}{loadhyph-eo.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['esperanto']={ \
			  loader='loadhyph-eo.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-eo.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
