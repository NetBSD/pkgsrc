# $NetBSD: Makefile,v 1.1.1.1 2011/03/16 18:14:16 minskim Exp $

DISTNAME=	collection-genericrecommended
PKGNAME=	tex-${DISTNAME}-2010
CATEGORIES=	print
MASTER_SITES=	# empty
TEXLIVE_REV=	19849

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Recommended generic packages

DEPENDS+=	tex-collection-basic-[0-9]*:../../print/tex-collection-basic
DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
DEPENDS+=	tex-fontname-[0-9]*:../../fonts/tex-fontname
DEPENDS+=	tex-genmisc-[0-9]*:../../print/tex-genmisc
DEPENDS+=	tex-kastrup-[0-9]*:../../math/tex-kastrup
DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-path-[0-9]*:../../print/tex-path
DEPENDS+=	tex-tex-ps-[0-9]*:../../graphics/tex-tex-ps
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
