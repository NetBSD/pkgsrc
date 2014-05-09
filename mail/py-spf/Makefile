# $NetBSD: Makefile,v 1.3 2014/05/09 07:37:10 wiz Exp $

VERSION=	2.0.8
DISTNAME=	pyspf-${VERSION}
PKGNAME=	${PYPKGPREFIX}-spf-${VERSION}
CATEGORIES=	mail python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pyspf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pyspf
COMMENT=	Python implementation of the RFC 4408 SPF protocol
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-dns>=0:../../net/py-dns

EGG_NAME=	pyspf-${VERSION}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-dns

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
