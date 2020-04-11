# $NetBSD: Makefile,v 1.3 2020/04/11 07:27:37 adam Exp $

DISTNAME=	testscenarios-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testscenarios/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/testscenarios
COMMENT=	Pyunit extension for dependency injection
LICENSE=	apache-2.0 OR modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

TEST_TARGET=	check

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
