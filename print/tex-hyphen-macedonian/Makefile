# $NetBSD: Makefile,v 1.3 2021/05/30 08:04:46 markd Exp $

DISTNAME=	hyphen-macedonian
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Macedonian hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	macedonian loadhyph-mk.tex
TEX_HYPHEN_DEF+=	\\addlanguage{macedonian}{loadhyph-mk.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['macedonian']={ \
			  loader='loadhyph-mk.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-mk.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
