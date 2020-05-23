# $NetBSD: Makefile,v 1.5 2020/05/23 07:55:15 adam Exp $

DISTNAME=	netaddr-0.7.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/netaddr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/drkjam/netaddr
COMMENT=	Python library for manipluating network addresses
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	netaddr/eui/ieee.py
REPLACE_PYTHON+=	netaddr/ip/iana.py
REPLACE_PYTHON+=	netaddr/tools/netaddr

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} netaddr netaddr${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
