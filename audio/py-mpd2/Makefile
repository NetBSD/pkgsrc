# $NetBSD: Makefile,v 1.7 2024/11/11 07:27:52 wiz Exp $

DISTNAME=	python-mpd2-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-mpd2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://musicpd.org/libs/python-mpd2/
COMMENT=	Python mpd client library
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
