# $NetBSD: Makefile,v 1.2 2026/09/23 06:12:41 wiz Exp $

DISTNAME=	internetarchive-5.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/internetarchive/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jjjake/internetarchive
COMMENT=	Python interface to archive.org
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=83:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jsonpatch>=0.4:../../textproc/py-jsonpatch
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.0.0:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.26.0:../../www/py-urllib3
# test data is missing in pypi distfile
#TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0:../../net/py-responses

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	ia

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
