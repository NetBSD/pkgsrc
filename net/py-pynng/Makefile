# $NetBSD: Makefile,v 1.9 2025/01/16 08:11:29 adam Exp $

DISTNAME=	pynng-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pynng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/codypiersall/pynng
COMMENT=	Ergonomic bindings for nanomsg next generation (nng) in Python
LICENSE=	mit

USE_TOOLS+=	cmake

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-sniffio-[0-9]*:../../misc/py-sniffio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-trio-[0-9]*:../../devel/py-test-trio

.include "../../mk/compiler.mk"
.if empty(PKGSRC_COMPILER:Mclang)
.include "../../devel/libatomic/buildlink3.mk"
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
