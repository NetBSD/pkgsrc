# $NetBSD: Makefile,v 1.16 2025/05/07 11:44:19 markd Exp $

DISTNAME=	hyphen-coptic
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	73410

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Coptic
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	coptic loadhyph-cop.tex
TEX_HYPHEN_DEF+=	\\addlanguage{coptic}{loadhyph-cop.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['coptic']={ \
			  loader='loadhyph-cop.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-cop.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
