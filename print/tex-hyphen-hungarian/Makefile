# $NetBSD: Makefile,v 1.13 2020/05/10 04:32:01 markd Exp $

DISTNAME=	hyphen-hungarian
PKGNAME=	tex-${DISTNAME}-2019.51186
PKGREVISION=	1
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	New Hungarian hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	hungarian loadhyph-hu.tex
TEX_HYPHEN_DEF+=	\\addlanguage{hungarian}{loadhyph-hu.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['hungarian']={ \
			  loader='loadhyph-hu.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-hu.pat.txt', \
			  hyphenation='', \
			},

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
