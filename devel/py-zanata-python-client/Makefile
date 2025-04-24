# $NetBSD: Makefile,v 1.18 2025/04/24 07:17:19 wiz Exp $

DISTNAME=	zanata-python-client-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zanata/}
GITHUB_PROJECT=	zanata-python-client
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://zanata.org/
COMMENT=	Zanata translation service client written in Python
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-minimock-[0-9]*:../../devel/py-minimock
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

# as of 1.5.3
# 1 error

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
