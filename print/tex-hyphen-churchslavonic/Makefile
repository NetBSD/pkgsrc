# $NetBSD: Makefile,v 1.5 2022/09/29 06:07:26 markd Exp $

DISTNAME=	hyphen-churchslavonic
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58609

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://ctan.org/pkg/hyphen-churchslavonic
COMMENT=	Church Slavonic hyphenation patterns

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
