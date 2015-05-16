# $NetBSD: Makefile,v 1.1 2015/05/16 02:51:22 markd Exp $

DISTNAME=	hyphen-armenian
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	23085

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Armenian hyphenation patterns

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	armenian loadhyph-hy.tex
TEX_HYPHEN_DEF+=	\\addlanguage{armenian}{loadhyph-hy.tex}{}{1}{2}
TEX_HYPHEN_LUA+=	['armenian']={ \
			  loader='loadhyph-hy.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-hy.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
