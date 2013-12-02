# $NetBSD: Makefile,v 1.2 2013/12/02 19:36:06 minskim Exp $

DISTNAME=	collection-genericrecommended
PKGNAME=	tex-${DISTNAME}-2013
CATEGORIES=	print
MASTER_SITES=	# empty
TEXLIVE_REV=	30396

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Recommended generic packages

DEPENDS+=	tex-collection-basic>=2013:../../print/tex-collection-basic
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
