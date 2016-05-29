# $NetBSD: Makefile,v 1.4 2016/05/29 21:28:42 wiz Exp $

DISTNAME=	pytest-runner-2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/46/6c/ff61a9e0d513222afa3529bdb565a465812b7e50b218a5afd705f46b258c/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pytest-runner
COMMENT=	Invoke py.test as distutils command with dependency resolution
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
