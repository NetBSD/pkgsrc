# $NetBSD: Makefile,v 1.9 2025/05/07 11:44:21 markd Exp $

DISTNAME=	hyphen-friulan
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	73410

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Friulan hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	friulan loadhyph-fur.tex
TEX_HYPHEN_DEF+=	\\addlanguage{friulan}{loadhyph-fur.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['friulan']={ \
			  loader='loadhyph-fur.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-fur.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
