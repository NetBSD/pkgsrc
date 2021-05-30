# $NetBSD: Makefile,v 1.13 2021/05/30 08:04:49 markd Exp $

DISTNAME=	hyphen-welsh
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Welsh
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	welsh loadhyph-cy.tex
TEX_HYPHEN_DEF+=	\\addlanguage{welsh}{loadhyph-cy.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['welsh']={ \
			  loader='loadhyph-cy.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='hyph-cy.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
