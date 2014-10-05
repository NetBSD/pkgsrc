# $NetBSD: Makefile,v 1.4 2014/10/05 20:21:30 rodent Exp $
#

DISTNAME=	python-bitcoinlib-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance net python
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-bitcoinlib/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/petertodd/python-bitcoinlib
COMMENT=	Python bitcoin library
LICENSE=	gnu-lgpl-v2.1 AND mit

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/1}

PYTHON_VERSIONS_INCOMPATIBLE=	26

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
