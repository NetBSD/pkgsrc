# $NetBSD: Makefile,v 1.7 2020/05/10 04:32:01 markd Exp $

DISTNAME=	hyphen-friulan
PKGNAME=	tex-${DISTNAME}-2019.51186
PKGREVISION=	1
TEXLIVE_REV=	51186

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Friulan hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	friulan loadhyph-fur.tex
TEX_HYPHEN_DEF+=	\\addlanguage{friulan}{loadhyph-fur.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['friulan']={ \
			  loader='loadhyph-fur.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-fur.pat.txt', \
			  hyphenation='', \
			},

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
