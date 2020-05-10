# $NetBSD: Makefile,v 1.8 2020/05/10 04:32:03 markd Exp $

DISTNAME=	hyphen-romansh
PKGNAME=	tex-${DISTNAME}-2019.51186
PKGREVISION=	1
TEXLIVE_REV=	51186

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Romansh hyphenation patterns
LICENSE=	lppl-1.3c

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

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
