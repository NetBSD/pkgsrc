# $NetBSD: Makefile,v 1.6 2015/04/01 02:53:12 rodent Exp $

DISTNAME=	python-bitcoinlib-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance net python
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-bitcoinlib/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/petertodd/python-bitcoinlib
COMMENT=	Python bitcoin library
LICENSE=	gnu-lgpl-v2.1 AND mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	26

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
