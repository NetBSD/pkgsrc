# $NetBSD: Makefile,v 1.9 2025/04/12 10:59:19 adam Exp $

DISTNAME=	flufl.testing-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.testing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/warsaw/flufl.testing
COMMENT=	Small collection of test tool plugins
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

WHEEL_NAME=	${DISTNAME:S/./_/}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
