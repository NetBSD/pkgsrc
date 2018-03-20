# $NetBSD: Makefile,v 1.1 2018/03/20 15:40:48 khorben Exp $

DISTNAME=	pysha3-1.0.2
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysha3/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://pypi.python.org/pypi/pysha3/
COMMENT=	SHA-3 wrapper (keccak) for Python
LICENSE=	python-software-foundation

USE_LANGUAGES=	c

PYTHON_VERSIONS_ACCEPTED=	35 34 27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
