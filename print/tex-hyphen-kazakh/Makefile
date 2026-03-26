# $NetBSD: Makefile,v 1.1 2026/03/26 08:12:17 markd Exp $

DISTNAME=	hyphen-kazakh
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78069

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Kazakh hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	kazakh loadhyph-kk.tex
TEX_HYPHEN_DEF+=	\\addlanguage{kazakh}{loadhyph-kk.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['kazakh']={ \
			  loader='loadhyph-kk.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-kk.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
