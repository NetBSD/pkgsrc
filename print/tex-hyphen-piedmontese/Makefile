# $NetBSD: Makefile,v 1.8 2021/05/30 08:04:47 markd Exp $

DISTNAME=	hyphen-piedmontese
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Piedmontese hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	piedmontese loadhyph-pms.tex
TEX_HYPHEN_DEF+=	\\addlanguage{piedmontese}{loadhyph-pms.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['piedmontese']={ \
			  loader='loadhyph-pms.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-pms.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
