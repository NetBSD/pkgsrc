# $NetBSD: Makefile,v 1.4 2022/01/05 15:41:08 wiz Exp $

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

PYTHON_VERSIONED_DEPENDENCIES=	test

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ptw ptw-${PYVERSSUFFIX} && \
	${MV} pytest-watch pytest-watch-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
