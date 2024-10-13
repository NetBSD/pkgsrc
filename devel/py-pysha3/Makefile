# $NetBSD: Makefile,v 1.6 2024/10/13 19:56:58 wiz Exp $

DISTNAME=	pysha3-1.0.2
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysha3/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/tiran/pysha3
COMMENT=	SHA-3 wrapper (keccak) for Python
LICENSE=	python-software-foundation

# actually, only for python < 3.6, but it builds up to 3.10
PYTHON_VERSIONS_INCOMPATIBLE=	311 312 313

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
