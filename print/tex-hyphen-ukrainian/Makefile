# $NetBSD: Makefile,v 1.7 2016/06/16 04:06:09 markd Exp $

DISTNAME=	hyphen-ukrainian
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Ukrainian
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-ukrhyph>=2009:../../print/tex-ukrhyph

TEX_HYPHEN_DAT+=	ukrainian loadhyph-uk.tex
TEX_HYPHEN_DEF+=	\\addlanguage{ukrainian}{loadhyph-uk.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['ukrainian']={ \
			  loader='loadhyph-uk.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-uk.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
