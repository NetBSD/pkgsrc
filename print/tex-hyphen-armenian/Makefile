# $NetBSD: Makefile,v 1.2 2016/06/16 04:06:05 markd Exp $

DISTNAME=	hyphen-armenian
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40340

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Armenian hyphenation patterns
LICENSE=	lppl-1.3c

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
