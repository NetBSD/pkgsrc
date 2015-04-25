# $NetBSD: Makefile,v 1.4 2015/04/25 14:23:18 tnn Exp $

DISTNAME=	cairocffi-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/c/cairocffi/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/cairocffi
COMMENT=	CFFI-based Cairo bindings for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi>=0.6:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser

USE_LANGUAGES=	# none

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
