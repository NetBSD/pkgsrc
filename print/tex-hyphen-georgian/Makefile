# $NetBSD: Makefile,v 1.10 2026/03/26 08:07:43 markd Exp $

DISTNAME=	hyphen-georgian
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78069

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Georgian hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	georgian loadhyph-ka.tex
TEX_HYPHEN_DEF+=	\\addlanguage{georgian}{loadhyph-ka.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['georgian']={ \
			  loader='loadhyph-ka.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={}, \
			  patterns='hyph-ka.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
