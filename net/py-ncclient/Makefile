# $NetBSD: Makefile,v 1.23 2025/05/21 14:47:58 adam Exp $

DISTNAME=	ncclient-0.6.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ncclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ncclient/ncclient
COMMENT=	NETCONF Python client
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.3.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.15.0:../../security/py-paramiko

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
