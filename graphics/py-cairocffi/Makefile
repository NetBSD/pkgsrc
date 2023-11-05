# $NetBSD: Makefile,v 1.25 2023/11/05 13:39:45 wiz Exp $

DISTNAME=	cairocffi-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cairocffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/cairocffi
COMMENT=	CFFI-based Cairo bindings for Python
LICENSE=	modified-bsd

PYTHON_VERSIONED_DEPENDENCIES=	cffi

USE_LANGUAGES=	# none

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
