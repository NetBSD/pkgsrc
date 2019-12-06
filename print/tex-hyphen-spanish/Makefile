# $NetBSD: Makefile,v 1.10 2019/12/06 20:21:41 markd Exp $

DISTNAME=	hyphen-spanish
PKGNAME=	tex-${DISTNAME}-4.5.2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Spanish
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	spanish loadhyph-es.tex
TEX_HYPHEN_DAT+=	= espanol
TEX_HYPHEN_DEF+=	\\addlanguage{spanish}{loadhyph-es.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{espanol}{loadhyph-es.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['spanish']={ \
			  loader='loadhyph-es.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={'espanol'}, \
			  patterns='hyph-es.pat.txt', \
			  hyphenation='', \
			},

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
