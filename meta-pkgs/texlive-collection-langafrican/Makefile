# $NetBSD: Makefile,v 1.5 2016/06/16 04:03:14 markd Exp $

DISTNAME=	collection-langafrican
PKGNAME=	texlive-${DISTNAME}-2016
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	30372

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	African scripts TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-ethiop-[0-9]*:../../print/tex-ethiop
DEPENDS+=	tex-ethiop-t1-[0-9]*:../../fonts/tex-ethiop-t1
DEPENDS+=	tex-fc-[0-9]*:../../fonts/tex-fc
DEPENDS+=	tex-hyphen-ethiopic-[0-9]*:../../print/tex-hyphen-ethiopic

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
