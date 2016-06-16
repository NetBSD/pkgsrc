# $NetBSD: Makefile,v 1.6 2016/06/16 04:03:16 markd Exp $

DISTNAME=	collection-plainextra
PKGNAME=	texlive-${DISTNAME}-2016
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	37156

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Plain TeX packages

DEPENDS+=	texlive-collection-basic>=2014:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-epsf-dvipdfmx-[0-9]*:../../print/tex-epsf-dvipdfmx
DEPENDS+=	tex-figflow-[0-9]*:../../print/tex-figflow
DEPENDS+=	tex-fixpdfmag-[0-9]*:../../print/tex-fixpdfmag
DEPENDS+=	tex-font-change-[0-9]*:../../print/tex-font-change
DEPENDS+=	tex-fontch-[0-9]*:../../print/tex-fontch
DEPENDS+=	tex-getoptk-[0-9]*:../../print/tex-getoptk
DEPENDS+=	tex-gfnotation-[0-9]*:../../print/tex-gfnotation
DEPENDS+=	tex-graphics-pln-[0-9]*:../../graphics/tex-graphics-pln
DEPENDS+=	tex-hyplain-[0-9]*:../../print/tex-hyplain
DEPENDS+=	tex-js-misc-[0-9]*:../../print/tex-js-misc
DEPENDS+=	tex-mkpattern-[0-9]*:../../print/tex-mkpattern
DEPENDS+=	tex-newsletr-[0-9]*:../../print/tex-newsletr
DEPENDS+=	tex-pitex-[0-9]*:../../print/tex-pitex
DEPENDS+=	tex-placeins-plain-[0-9]*:../../print/tex-placeins-plain
DEPENDS+=	tex-plipsum-[0-9]*:../../print/tex-plipsum
DEPENDS+=	tex-plnfss-[0-9]*:../../print/tex-plnfss
DEPENDS+=	tex-plstmary-[0-9]*:../../print/tex-plstmary
DEPENDS+=	tex-present-[0-9]*:../../print/tex-present
DEPENDS+=	tex-resumemac-[0-9]*:../../print/tex-resumemac
DEPENDS+=	tex-texinfo-[0-9]*:../../print/tex-texinfo
DEPENDS+=	tex-timetable-[0-9]*:../../print/tex-timetable
DEPENDS+=	tex-treetex-[0-9]*:../../print/tex-treetex
DEPENDS+=	tex-varisize-[0-9]*:../../print/tex-varisize
# xii is a "fun" package and the only files are in tex-xii-doc
#DEPENDS+=	tex-xii-[0-9]*:../../print/tex-xii

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
