# $NetBSD: Makefile,v 1.6 2020/06/20 07:27:44 adam Exp $

DISTNAME=	netaddr-0.7.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/netaddr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/drkjam/netaddr
COMMENT=	Python library for manipluating network addresses
LICENSE=	modified-bsd

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 37
DEPENDS+=	${PYPKGPREFIX}-importlib-resources-[0-9]*:../../devel/py-importlib-resources
.endif

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	netaddr/eui/ieee.py
REPLACE_PYTHON+=	netaddr/ip/iana.py
REPLACE_PYTHON+=	netaddr/tools/netaddr

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} netaddr netaddr-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
