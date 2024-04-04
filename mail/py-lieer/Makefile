# $NetBSD: Makefile,v 1.1 2024/04/04 04:23:55 wiz Exp $

DISTNAME=	lieer-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lieer/}

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://github.com/gauteh/lieer
COMMENT=	Email synchronization between notmuch and GMail
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-notmuch2-[0-9]*:../../mail/py-notmuch2
DEPENDS+=	${PYPKGPREFIX}-google-api-python-client-[0-9]*:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-google-auth-oauthlib-[0-9]*:../../security/py-google-auth-oauthlib
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/gmi bin/gmi-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
