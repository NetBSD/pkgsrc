# $NetBSD: Makefile,v 1.15 2026/03/26 08:07:47 markd Exp $

DISTNAME=	hyphen-swedish
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78069

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Swedish
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	swedish loadhyph-sv.tex
TEX_HYPHEN_DEF+=	\\addlanguage{swedish}{loadhyph-sv.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['swedish']={ \
			  loader='loadhyph-sv.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-sv.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
