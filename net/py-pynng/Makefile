# $NetBSD: Makefile,v 1.12 2026/10/26 06:36:26 wiz Exp $

DISTNAME=	pynng-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pynng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/codypiersall/pynng
COMMENT=	Ergonomic bindings for nanomsg next generation (nng) in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-sniffio-[0-9]*:../../misc/py-sniffio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-trio-[0-9]*:../../devel/py-test-trio

USE_TOOLS+=	cmake

.include "../../mk/compiler.mk"
.if empty(PKGSRC_COMPILER:Mclang)
.include "../../devel/libatomic/buildlink3.mk"
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
