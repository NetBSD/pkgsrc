# $NetBSD: Makefile,v 1.3 2015/06/14 13:28:52 markd Exp $

DISTNAME=	collection-formatsextra
PKGNAME=	texlive-${DISTNAME}-2015
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	33658

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Additional formats for TeX

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-edmac-[0-9]*:../../print/tex-edmac
DEPENDS+=	tex-eplain-[0-9]*:../../print/tex-eplain
DEPENDS+=	tex-lollipop-[0-9]*:../../print/tex-lollipop
DEPENDS+=	tex-mltex-[0-9]*:../../print/tex-mltex
DEPENDS+=	tex-psizzl-[0-9]*:../../print/tex-psizzl
DEPENDS+=	tex-startex-[0-9]*:../../print/tex-startex
DEPENDS+=	tex-texsis-[0-9]*:../../print/tex-texsis

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
