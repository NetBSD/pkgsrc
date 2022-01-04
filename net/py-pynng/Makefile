# $NetBSD: Makefile,v 1.6 2022/01/04 20:54:31 wiz Exp $

DISTNAME=	pynng-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pynng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/codypiersall/pynng
COMMENT=	Ergonomic bindings for nanomsg next generation (nng) in Python
LICENSE=	mit

USE_TOOLS+=	cmake

TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-sniffio-[0-9]*:../../misc/py-sniffio

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/libatomic/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
