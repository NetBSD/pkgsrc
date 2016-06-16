# $NetBSD: Makefile,v 1.3 2016/06/16 04:03:13 markd Exp $

DISTNAME=	collection-context
PKGNAME=	texlive-${DISTNAME}-2016pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	36190

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	ConTeXt and packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context
# depend jmn
# depend context-account
# depend context-algorithmic
# depend context-animation
# depend context-annotation
# depend context-bnf
# depend context-chromato
# depend context-construction-plan
# depend context-cyrillicnumbers
# depend context-degrade
# depend context-fancybreak
# depend context-filter
# depend context-fixme
# depend context-french
# depend context-fullpage
# depend context-games
# depend context-gantt
# depend context-gnuplot
# depend context-letter
# depend context-lettrine
# depend context-lilypond
# depend context-mathsets
# depend context-notes-zh-cn
# depend context-rst
# depend context-ruby
# depend context-simplefonts
# depend context-simpleslides
# depend context-title
# depend context-transliterator
# depend context-typearea
# depend context-typescripts
# depend context-vim
# depend context-visualcounter

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
