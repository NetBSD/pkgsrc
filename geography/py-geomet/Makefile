# $NetBSD: Makefile,v 1.3 2025/04/16 14:38:57 adam Exp $

DISTNAME=	geomet-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geomet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/geomet/geomet
COMMENT=	Pure Python conversion library for common geospatial data formats
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} geomet geomet-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
