# $NetBSD: Makefile,v 1.15 2026/03/26 08:07:42 markd Exp $

DISTNAME=	hyphen-croatian
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78069

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Croatian hyphenation
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	croatian loadhyph-hr.tex
TEX_HYPHEN_DEF+=	\\addlanguage{croatian}{loadhyph-hr.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['croatian']={ \
			  loader='loadhyph-hr.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-hr.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
