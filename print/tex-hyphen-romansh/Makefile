# $NetBSD: Makefile,v 1.9 2021/05/30 08:04:47 markd Exp $

DISTNAME=	hyphen-romansh
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58652

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Romansh hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	romansh loadhyph-rm.tex
TEX_HYPHEN_DEF+=	\\addlanguage{romansh}{loadhyph-rm.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['romansh']={ \
			  loader='loadhyph-rm.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-rm.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
