# $NetBSD: Makefile,v 1.14 2018/11/12 14:35:23 kleink Exp $

DISTNAME=	cairocffi-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cairocffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/cairocffi
COMMENT=	CFFI-based Cairo bindings for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi>=0.6:../../devel/py-cffi

USE_LANGUAGES=	# none

.include "../../mk/bsd.prefs.mk"
.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SOEXT=		dylib
.else
SOEXT=		so
.endif

SUBST_CLASSES+=		dllpath
SUBST_STAGE.dllpath=	pre-configure
SUBST_MESSAGE.dllpath=	Fix libcairo path.
SUBST_FILES.dllpath=	cairocffi/__init__.py
SUBST_VARS.dllpath=	PREFIX SOEXT

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
