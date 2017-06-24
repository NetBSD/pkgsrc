# $NetBSD: Makefile,v 1.1 2017/06/24 06:47:58 adam Exp $

DISTNAME=	uvloop-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uvloop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/uvloop
COMMENT=	Fast implementation of asyncio event loop on top of libuv
LICENSE=	mit AND apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
#BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
# TEST_DEPENDS

PYTHON_VERSIONS_ACCEPTED=	36 35

USE_LANGUAGES=		c

#post-install:
#	cd ${DESTDIR}${PREFIX}/bin && \
#		${MV} py.test py.test-${PYVERSSUFFIX} && \
#		${MV} pytest pytest-${PYVERSSUFFIX} || ${TRUE}

.include "../../devel/libuv/buildlink3.mk"
#.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
