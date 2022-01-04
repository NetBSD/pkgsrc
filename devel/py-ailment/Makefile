#	$NetBSD: Makefile,v 1.3 2022/01/04 20:52:48 wiz Exp $

PKGREVISION= 1
.include "../../devel/py-angr/version.mk"

DISTNAME=	ailment-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ailment/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/angr/ailment
COMMENT=	The angr intermediate language
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	27

TEST_DEPENDS+=	${PYPKGPREFIX}-archinfo>=0:../../devel/py-archinfo
TEST_DEPENDS+=	${PYPKGPREFIX}-pyvex>=0:../../devel/py-pyvex

do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} \
	${PYTHONBIN} -m unittest discover

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
