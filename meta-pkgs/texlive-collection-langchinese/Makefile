# $NetBSD: Makefile,v 1.22 2024/03/21 20:00:53 markd Exp $

DISTNAME=	collection-langchinese
PKGNAME=	texlive-${DISTNAME}-2024pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	63995

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Chinese TeX packages

DEPENDS+=	texlive-collection-langcjk-[0-9]*:../../meta-pkgs/texlive-collection-langcjk

DEPENDS+=	tex-arphic-[0-9]*:../../fonts/tex-arphic
DEPENDS+=	tex-arphic-ttf-[0-9]*:../../fonts/tex-arphic-ttf
# asymptote-by-example-zh-cn is documentation only
# asymptote-faq-zh-cn is documentation only
# asymptote-manual-zh-cn is documentation only
DEPENDS+=	tex-cmsd-[0-9]*:../../fonts/tex-cmsd
DEPENDS+=	tex-ctex-[0-9]*:../../print/tex-ctex
# ctex-faq is documentation only
# depend exam-zh
DEPENDS+=	tex-fandol-[0-9]*:../../fonts/tex-fandol
# depend fduthesis
# depend hanzibox
DEPENDS+=	tex-hyphen-chinese-[0-9]*:../../print/tex-hyphen-chinese
# install-latex-guide-zh-cn is documentation only
# impatient-cn is documentation only
# latex-notes-zh-cn is documentation only
# lshort-chinese is documentation only
# depend nanicolle
# depend njurepo
# depend pgfornament-han
# depend qyxf-book
# texlive-zh-cn is documentation only
# texproposal is documentation only
# tlmgr-intro-zh-cn is documentation only
# depend upzhkinsoku
DEPENDS+=	tex-xpinyin-[0-9]*:../../print/tex-xpinyin
# depend xtuthesis
# depend zhlineskip
# depend zhlipsum
DEPENDS+=	tex-zhmetrics-[0-9]*:../../fonts/tex-zhmetrics
DEPENDS+=	tex-zhmetrics-uptex-[0-9]*:../../fonts/tex-zhmetrics-uptex
DEPENDS+=	tex-zhnumber-[0-9]*:../../math/tex-zhnumber
# depend zhspacing

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
