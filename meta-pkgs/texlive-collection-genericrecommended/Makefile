# $NetBSD: Makefile,v 1.3 2016/06/16 04:03:13 markd Exp $

DISTNAME=	collection-genericrecommended
PKGNAME=	texlive-${DISTNAME}-2016
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	35655

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Recommended generic packages for TeX

DEPENDS+=	texlive-collection-basic>=2013:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-apnum>=1.1:../../math/tex-apnum
DEPENDS+=	tex-epsf>=2.7.4:../../print/tex-epsf
DEPENDS+=	tex-fontname>=2013:../../fonts/tex-fontname
DEPENDS+=	tex-genmisc>=2013:../../print/tex-genmisc
DEPENDS+=	tex-kastrup>=2010:../../math/tex-kastrup
DEPENDS+=	tex-multido>=1.42:../../devel/tex-multido
DEPENDS+=	tex-path>=3.05:../../print/tex-path
DEPENDS+=	tex-tex-ps>=2010:../../graphics/tex-tex-ps
DEPENDS+=	tex-ulem>=2013:../../print/tex-ulem

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
