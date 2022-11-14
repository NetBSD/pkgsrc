# $NetBSD: Makefile,v 1.5 2022/11/14 17:16:04 wiz Exp $

DISTNAME=	pytest-watch-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-watch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joeyespo/pytest-watch
COMMENT=	Continuous pytest runner
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.3:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.4.0:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.6.0:../../sysutils/py-watchdog
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ptw ptw-${PYVERSSUFFIX} && \
	${MV} pytest-watch pytest-watch-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
