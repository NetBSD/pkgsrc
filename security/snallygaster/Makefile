# $NetBSD: Makefile,v 1.10 2026/09/23 12:59:18 adam Exp $

DISTNAME=	snallygaster-0.0.15
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/snallygaster/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/hannob/snallygaster
COMMENT=	Tool to scan for secret files on HTTP servers
LICENSE=	cc0-1.0-universal

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-dns>=0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-lxml>=0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-urllib3>=0:../../www/py-urllib3

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
