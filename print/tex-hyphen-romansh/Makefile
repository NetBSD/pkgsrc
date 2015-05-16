# $NetBSD: Makefile,v 1.1 2015/05/16 02:51:23 markd Exp $

DISTNAME=	hyphen-romansh
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	25990

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Romansh hyphenation patterns

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	romansh loadhyph-rm.tex
TEX_HYPHEN_DEF+=	\\addlanguage{romansh}{loadhyph-rm.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['romansh']={ \
			  loader='loadhyph-rm.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-rm.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
