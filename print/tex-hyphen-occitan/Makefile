# $NetBSD: Makefile,v 1.7 2026/03/26 08:07:46 markd Exp $

DISTNAME=	hyphen-occitan
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78069

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Occitan hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

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

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
