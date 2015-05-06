# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:43 markd Exp $

DISTNAME=	collection-langchinese
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	35576

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Chinese TeX packages

DEPENDS+=	texlive-collection-langcjk-[0-9]*:../../meta-pkgs/texlive-collection-langcjk

DEPENDS+=	tex-arphic-[0-9]*:../../fonts/tex-arphic
# depend asymptote-by-example-zh-cn
# depend asymptote-faq-zh-cn
# depend asymptote-manual-zh-cn
DEPENDS+=	tex-cmsd-[0-9]*:../../fonts/tex-cmsd
# depend ctex
# depend ctex-faq
# depend fandol
DEPENDS+=	tex-hyphen-chinese-[0-9]*:../../print/tex-hyphen-chinese
# depend impatient-cn
# depend latex-notes-zh-cn
# depend lshort-chinese
# depend texlive-zh-cn
# depend xpinyin
# depend zhmetrics
# depend zhnumber
# depend zhspacing

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
