# $NetBSD: Makefile,v 1.12 2019/08/04 12:08:34 markd Exp $

DISTNAME=	hyphen-coptic
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Coptic
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

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
