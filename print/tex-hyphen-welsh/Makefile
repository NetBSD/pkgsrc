# $NetBSD: Makefile,v 1.10 2019/08/04 21:02:45 markd Exp $

DISTNAME=	hyphen-welsh
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Welsh
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

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
