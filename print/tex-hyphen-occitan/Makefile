# $NetBSD: Makefile,v 1.3 2020/05/10 04:32:03 markd Exp $

DISTNAME=	hyphen-occitan
PKGNAME=	tex-${DISTNAME}-2019
PKGREVISION=	1
TEXLIVE_REV=	51186

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hyphen-occitan
COMMENT=	Occitan hyphenation patterns

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	occitan loadhyph-oc.tex
TEX_HYPHEN_DEF+=	\\addlanguage{occitan}{loadhyph-oc.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['occitan']={ \
			  loader='loadhyph-oc.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-oc.pat.txt', \
			  hyphenation='', \
			},

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
