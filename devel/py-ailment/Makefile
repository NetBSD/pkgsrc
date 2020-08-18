#	$NetBSD: Makefile,v 1.1 2020/08/18 20:24:57 riastradh Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	ailment-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ailment/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/angr/ailment
COMMENT=	The angr intermediate language
LICENSE=	2-clause-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-archinfo>=0:../../devel/py-archinfo
TEST_DEPENDS+=	${PYPKGPREFIX}-pyvex>=0:../../devel/py-pyvex

do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} \
	${PYTHONBIN} -m unittest discover

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
