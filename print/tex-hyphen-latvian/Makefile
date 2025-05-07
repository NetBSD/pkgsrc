# $NetBSD: Makefile,v 1.9 2025/05/07 11:44:23 markd Exp $

DISTNAME=	hyphen-latvian
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	73410

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Latvian hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	latvian loadhyph-lv.tex
TEX_HYPHEN_DEF+=	\\addlanguage{latvian}{loadhyph-lv.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['latvian']={ \
			  loader='loadhyph-lv.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-lv.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
