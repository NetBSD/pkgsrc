# $NetBSD: Makefile,v 1.8 2021/05/30 08:04:48 markd Exp $

DISTNAME=	hyphen-turkmen
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Turkmen hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	turkmen loadhyph-tk.tex
TEX_HYPHEN_DEF+=	\\addlanguage{turkmen}{loadhyph-tk.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['turkmen']={ \
			  loader='loadhyph-tk.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-tk.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
