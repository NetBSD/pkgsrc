# $NetBSD: Makefile,v 1.18 2025/03/15 19:28:21 adam Exp $

DISTNAME=	Pebble-5.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pebble/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/noxdafox/pebble
COMMENT=	Threading and multiprocessing eye-candy
LICENSE=	gnu-lgpl-v3

WHEEL_NAME=	${DISTNAME:tl}
WRKSRC=		${WRKDIR}/${DISTNAME:tl}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
