# $NetBSD: Makefile,v 1.5 2019/08/04 12:44:12 markd Exp $

DISTNAME=	hyphen-georgian
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Georgian hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

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
