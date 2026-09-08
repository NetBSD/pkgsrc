# $NetBSD: Makefile,v 1.73 2026/09/08 13:06:03 adam Exp $

DISTNAME=	urwid-4.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urwid/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://urwid.org/
COMMENT=	Curses-based Python user interface library
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80.8.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.1.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.4:../../devel/py-wcwidth
TEST_DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=0:../../devel/py-exceptiongroup
TEST_DEPENDS+=	${PYPKGPREFIX}-gobject3>=0:../../devel/py-gobject3
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=5:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-trio>=0:../../devel/py-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=0:../../net/py-twisted
TEST_DEPENDS+=	${PYPKGPREFIX}-zmq>=0:../../net/py-zmq

USE_LANGUAGES=	# none

# two win32 tests error out, after removing them:
# 2 failed, 382 passed, 8 skipped, 219 warnings, 301 subtests passed
pre-test:
	${RM} -f ${WRKSRC}/urwid/display/_win32*

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
