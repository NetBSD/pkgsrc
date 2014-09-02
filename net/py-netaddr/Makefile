# $NetBSD: Makefile,v 1.1 2014/09/02 13:48:13 he Exp $

DISTNAME=	netaddr-0.7.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	https://pypi.python.org/packages/source/n/netaddr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/netaddr/
COMMENT=	Python library for manipluating network addresses
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

REPLACE_PYTHON+= netaddr/eui/ieee.py
REPLACE_PYTHON+= netaddr/ip/iana.py
REPLACE_PYTHON+= netaddr/tests/__init__.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
