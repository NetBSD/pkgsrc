# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:42 markd Exp $

DISTNAME=	collection-formatsextra
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	33658

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Additional formats for TeX

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend edmac
# depend eplain
# depend lollipop
DEPENDS+=	tex-mltex-[0-9]*:../../print/tex-mltex
# depend psizzl
# depend startex
# depend texsis

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
