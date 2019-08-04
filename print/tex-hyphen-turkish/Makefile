# $NetBSD: Makefile,v 1.10 2019/08/04 20:56:23 markd Exp $

DISTNAME=	hyphen-turkish
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Turkish
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	turkish loadhyph-tr.tex
TEX_HYPHEN_DEF+=	\\addlanguage{turkish}{loadhyph-tr.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['turkish']={ \
			  loader='loadhyph-tr.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-tr.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
