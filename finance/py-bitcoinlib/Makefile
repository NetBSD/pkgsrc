# $NetBSD: Makefile,v 1.4 2025/02/06 16:27:44 adam Exp $

DISTNAME=	python-bitcoinlib-0.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	finance net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-bitcoinlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/petertodd/python-bitcoinlib
COMMENT=	Python bitcoin library
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
