# $NetBSD: Makefile,v 1.1 2021/05/11 08:56:00 khorben Exp $

DISTNAME=	pynng-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pynng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/codypiersall/pynng
COMMENT=	Ergonomic bindings for nanomsg next generation (nng) in Python
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	39 38 37 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
