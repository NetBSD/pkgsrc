# $NetBSD: Makefile,v 1.3 2020/05/10 04:31:58 markd Exp $

DISTNAME=	hyphen-belarusian
PKGNAME=	tex-${DISTNAME}-2019
PKGREVISION=	1
TEXLIVE_REV=	51186

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Belarusian hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	belarusian loadhyph-be.tex
TEX_HYPHEN_DEF+=	\\addlanguage{belarusian}{loadhyph-be.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['belarusian']={ \
			  loader='loadhyph-be.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-be.pat.txt', \
			  hyphenation='', \
			},

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
