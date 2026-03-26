# $NetBSD: Makefile,v 1.10 2026/03/26 08:07:45 markd Exp $

DISTNAME=	hyphen-kurmanji
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78069

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Kurmanji hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	kurmanji loadhyph-kmr.tex
TEX_HYPHEN_DEF+=	\\addlanguage{kurmanji}{loadhyph-kmr.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['kurmanji']={ \
			  loader='loadhyph-kmr.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-kmr.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
