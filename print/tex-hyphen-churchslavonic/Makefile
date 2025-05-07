# $NetBSD: Makefile,v 1.6 2025/05/07 11:44:19 markd Exp $

DISTNAME=	hyphen-churchslavonic
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	73410

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Church Slavonic hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	churchslavonic loadhyph-cu.tex
TEX_HYPHEN_DEF+=	\\addlanguage{churchslavonic}{loadhyph-cu.tex}{}{1}{2}
TEX_HYPHEN_LUA+=	['churchslavonic']={ \
			  loader='loadhyph-cu.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-cu.pat.txt', \
			  hyphenation='hyph-cu.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
