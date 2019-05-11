# $NetBSD: Makefile,v 1.9 2019/05/11 06:57:27 markd Exp $

DISTNAME=	hyphen-portuguese
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50792

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Portuguese
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	portuguese loadhyph-pt.tex
TEX_HYPHEN_DAT+=	= portuges
TEX_HYPHEN_DAT+=	= brazil
TEX_HYPHEN_DAT+=	= brazilian
TEX_HYPHEN_DEF+=	\\addlanguage{portuguese}{loadhyph-pt.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\\addlanguage{portuges}{loadhyph-pt.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\\addlanguage{brazil}{loadhyph-pt.tex}{}{2}{3}
TEX_HYPHEN_DEF+=	\\addlanguage{brazilian}{loadhyph-pt.tex}{}{2}{3}
TEX_HYPHEN_LUA+=	['portuguese']={ \
			  loader='loadhyph-pt.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=3, \
			  synonyms={'portuges','brazil', 'brazilian',}, \
			  patterns='hyph-pt.pat.txt', \
			  hyphenation='hyph-pt.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
