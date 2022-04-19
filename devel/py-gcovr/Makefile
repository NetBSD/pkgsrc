# $NetBSD: Makefile,v 1.4 2022/04/19 12:03:11 tnn Exp $

DISTNAME=	gcovr-4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gcovr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/gcovr/
COMMENT=	Generate GCC code coverage reports
LICENSE=	modified-bsd

PYTHON_VERSIONED_DEPENDENCIES=	jinja2

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
