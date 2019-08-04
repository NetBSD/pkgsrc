# $NetBSD: Makefile,v 1.11 2019/08/04 20:59:40 markd Exp $

DISTNAME=	hyphen-ukrainian
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Ukrainian
LICENSE=	lppl-1.3c

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
