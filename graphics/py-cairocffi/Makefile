# $NetBSD: Makefile,v 1.8.2.1 2017/05/01 08:43:41 bsiegert Exp $

DISTNAME=	cairocffi-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cairocffi/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/cairocffi
COMMENT=	CFFI-based Cairo bindings for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi>=0.6:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser

USE_LANGUAGES=	# none

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
