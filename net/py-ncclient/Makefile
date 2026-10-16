# $NetBSD: Makefile,v 1.29 2026/10/16 19:44:09 adam Exp $

DISTNAME=	ncclient-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ncclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ncclient/ncclient
COMMENT=	NETCONF Python client
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.4:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.3.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-paramiko>=3.2.0:../../security/py-paramiko

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
