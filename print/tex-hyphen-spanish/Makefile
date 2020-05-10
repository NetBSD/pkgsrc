# $NetBSD: Makefile,v 1.12 2020/05/10 04:32:04 markd Exp $

DISTNAME=	hyphen-spanish
PKGNAME=	tex-${DISTNAME}-5.0
PKGREVISION=	1
TEXLIVE_REV=	54857

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Spanish hyphenation patterns
LICENSE=	mit

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

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
