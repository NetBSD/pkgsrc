# $NetBSD: Makefile,v 1.4 2014/12/23 18:52:03 joerg Exp $

DISTNAME=	jaraco.util-10.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./_/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/j/jaraco.util/
EXTRACT_SUFX=	.zip

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/jaraco.util
COMMENT=	General utility modules that supply commonly-used functionality
LICENSE=	mit

WRKSRC=		${WRKDIR}/jaraco.util-10.0.2
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-more-itertools>=2.2:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-hgtools-[0-9]*:../../devel/py-hgtools

REPLACE_PYTHON+=	jaraco/lang/python.py
REPLACE_PYTHON+=	jaraco/util/filesystem.py

pre-build:
	${CHMOD} go-w ${WRKSRC}/jaraco.util.egg-info/*

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
