# $NetBSD: Makefile,v 1.3 2021/05/13 19:35:54 khorben Exp $

DISTNAME=	pynng-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pynng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/codypiersall/pynng
COMMENT=	Ergonomic bindings for nanomsg next generation (nng) in Python
LICENSE=	mit

USE_TOOLS+=	cmake

DEPENDS+=	${PYPKGPREFIX}-sniffio-[0-9]*:../../misc/py-sniffio

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
