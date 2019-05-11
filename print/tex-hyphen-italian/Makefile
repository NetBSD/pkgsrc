# $NetBSD: Makefile,v 1.9 2019/05/11 06:57:26 markd Exp $

DISTNAME=	hyphen-italian
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50792

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for the Italian language
LICENSE=	gnu-lgpl-v2

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	italian loadhyph-it.tex
TEX_HYPHEN_DEF+=	\\addlanguage{italian}{loadhyph-it.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['italian']={ \
			  loader='loadhyph-it.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-it.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
