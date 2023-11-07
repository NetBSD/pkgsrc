# $NetBSD: Makefile,v 1.7 2023/11/07 22:38:01 wiz Exp $

DISTNAME=	testscenarios-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testscenarios/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/testscenarios
COMMENT=	Pyunit extension for dependency injection
LICENSE=	apache-2.0 OR modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

TEST_TARGET=	check

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
