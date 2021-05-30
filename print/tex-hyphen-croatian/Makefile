# $NetBSD: Makefile,v 1.13 2021/05/30 08:04:43 markd Exp $

DISTNAME=	hyphen-croatian
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Croatian hyphenation
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	croatian loadhyph-hr.tex
TEX_HYPHEN_DEF+=	\\addlanguage{croatian}{loadhyph-hr.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['croatian']={ \
			  loader='loadhyph-hr.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-hr.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
