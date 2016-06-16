# $NetBSD: Makefile,v 1.6 2016/06/16 04:06:06 markd Exp $

DISTNAME=	hyphen-french
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	41113

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for French
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	french loadhyph-fr.tex
TEX_HYPHEN_DAT+=	= patois
TEX_HYPHEN_DAT+=	= francais
TEX_HYPHEN_DEF+=	\\addlanguage{french}{loadhyph-fr.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\\addlanguage{patois}{loadhyph-fr.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\\addlanguage{francais}{loadhyph-fr.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['french']={ \
			  loader='loadhyph-fr.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={'patois','francais',}, \
			  patterns='hyph-fr.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
