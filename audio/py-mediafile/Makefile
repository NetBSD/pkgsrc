# $NetBSD: Makefile,v 1.3 2024/06/12 15:37:45 adam Exp $

DISTNAME=	mediafile-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mediafile/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/beetbox/mediafile
COMMENT=	Handles low-level interfacing for files' tags. Wraps Mutagen to
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.45:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-six>=1.9:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
