# $NetBSD: Makefile,v 1.12 2020/05/10 04:32:04 markd Exp $

DISTNAME=	hyphen-serbian
PKGNAME=	tex-${DISTNAME}-1.0a.2019.51186
PKGREVISION=	1
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Serbian Cyrillic
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	serbian loadhyph-sr-latn.tex
TEX_HYPHEN_DAT+=	serbianc loadhyph-sr-cyrl.tex
TEX_HYPHEN_DEF+=	\\addlanguage{serbian}{loadhyph-sr-latn.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{serbianc}{loadhyph-sr-cyrl.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['serbian']={ \
			  loader='loadhyph-sr-latn.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-sr-latn.pat.txt,hyph-sh-cyrl.pat.txt', \
			  hyphenation='hyph-sr-latn.hyp.txt,hyph-sh-cyrl.hyp.txt', \
			},
TEX_HYPHEN_LUA+=	['serbianc']={ \
			  loader='loadhyph-sr-cyrl.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-sr-latn.pat.txt,hyph-sh-cyrl.pat.txt', \
			  hyphenation='hyph-sr-latn.hyp.txt,hyph-sh-cyrl.hyp.txt', \
			},

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
