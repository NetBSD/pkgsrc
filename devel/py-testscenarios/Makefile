# $NetBSD: Makefile,v 1.4 2022/01/04 20:53:44 wiz Exp $

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

TEST_TARGET=	check

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
