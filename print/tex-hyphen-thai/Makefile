# $NetBSD: Makefile,v 1.10 2025/05/07 11:44:25 markd Exp $

DISTNAME=	hyphen-thai
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	73410

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Thai hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	thai loadhyph-th.tex
TEX_HYPHEN_DEF+=	\\addlanguage{thai}{loadhyph-th.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['thai']={ \
			  loader='loadhyph-th.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='hyph-th.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
