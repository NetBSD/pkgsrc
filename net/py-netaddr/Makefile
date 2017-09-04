# $NetBSD: Makefile,v 1.3 2017/09/04 18:08:26 wiz Exp $

DISTNAME=	netaddr-0.7.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/netaddr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/netaddr/
COMMENT=	Python library for manipluating network addresses
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

REPLACE_PYTHON+=	netaddr/eui/ieee.py
REPLACE_PYTHON+=	netaddr/ip/iana.py
REPLACE_PYTHON+=	netaddr/tools/netaddr

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
