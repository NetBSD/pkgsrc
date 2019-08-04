# $NetBSD: Makefile,v 1.10 2019/08/04 20:05:53 markd Exp $

DISTNAME=	hyphen-mongolian
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Mongolian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	mongolian loadhyph-mn-cyrl.tex
TEX_HYPHEN_DAT+=	mongolianlmc loadhyph-mn-cyrl-x-lmc.tex
TEX_HYPHEN_DEF+=	\\addlanguage{mongolian}{loadhyph-mn-cyrl.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{mongolianlmc}{loadhyph-mn-cyrl-x-lmc.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['mongolian']={ \
			  loader='loadhyph-mn-cyrl.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-mn-cyrl.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_LUA+=	['mongolianlmc']={ \
			  loader='loadhyph-mn-cyrl-x-lmc.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  special='disabled:only+for+8bit+montex+with+lmc+encoding', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
