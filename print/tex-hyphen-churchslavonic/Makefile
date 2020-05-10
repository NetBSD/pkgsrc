# $NetBSD: Makefile,v 1.3 2020/05/10 04:31:59 markd Exp $

DISTNAME=	hyphen-churchslavonic
PKGNAME=	tex-${DISTNAME}-2019
PKGREVISION=	1
TEXLIVE_REV=	51186

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hyphen-churchslavonic
COMMENT=	Church Slavonic hyphenation patterns

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

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

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
