# $NetBSD: Makefile,v 1.3 2020/08/18 20:24:58 riastradh Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	cle-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	cle
GITHUB_TAG=	103190d3899dc1b7e784edab23d0276245925b7d

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/cle/
COMMENT=	CLE Loads Everything (at least, many binary formats!)
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi>=0:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-minidump>=0:../../devel/py-minidump
DEPENDS+=	${PYPKGPREFIX}-pefile>=0:../../sysutils/py-pefile
DEPENDS+=	${PYPKGPREFIX}-pyelftools>=0.25:../../devel/py-pyelftools
DEPENDS+=	${PYPKGPREFIX}-pyvex>=${PKVERSION_NOREV}:../../devel/py-pyvex
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.0:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-xbe>=0.0.2:../../devel/py-xbe

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	${RUN} cd ${WRKSRC}/tests && \
	${SETENV} ${TEST_ENV} \
	${PYTHONBIN} -m unittest discover

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
