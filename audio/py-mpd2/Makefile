# $NetBSD: Makefile,v 1.4 2022/01/08 12:10:38 wiz Exp $

DISTNAME=	python-mpd2-3.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-mpd2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://musicpd.org/libs/python-mpd2/
COMMENT=	Python mpd client library
LICENSE=	gnu-lgpl-v3

# tox.ini not in pypi distfile
#TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
#TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
#TEST_DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
