# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:45 markd Exp $

DISTNAME=	collection-plainextra
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	35575

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Plain TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend epsf-dvipdfmx
# depend figflow
# depend fixpdfmag
# depend font-change
DEPENDS+=	tex-fontch-[0-9]*:../../print/tex-fontch
# depend getoptk
DEPENDS+=	tex-graphics-pln-[0-9]*:../../graphics/tex-graphics-pln
# depend hyplain
# depend js-misc
# depend mkpattern
# depend newsletr
# depend pitex
DEPENDS+=	tex-placeins-plain-[0-9]*:../../print/tex-placeins-plain
# depend plipsum
# depend plnfss
# depend plstmary
# depend present
# depend resumemac
DEPENDS+=	tex-texinfo-[0-9]*:../../print/tex-texinfo
# depend timetable
# depend treetex
# depend varisize
# depend xii

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
