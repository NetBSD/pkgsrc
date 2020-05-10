# $NetBSD: Makefile,v 1.12 2020/05/10 04:31:59 markd Exp $

DISTNAME=	hyphen-catalan
PKGNAME=	tex-${DISTNAME}-2019.51186
PKGREVISION=	1
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Catalan
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	catalan loadhyph-ca.tex
TEX_HYPHEN_DEF+=	\\addlanguage{catalan}{loadhyph-ca.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['catalan']={ \
			  loader='loadhyph-ca.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-ca.pat.txt', \
			  hyphenation='hyph-ca.hyp.txt', \
			},

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
