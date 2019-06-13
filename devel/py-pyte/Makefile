# $NetBSD: Makefile,v 1.1 2019/06/13 09:33:37 gson Exp $

DISTNAME=	pyte-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyte/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://github.com/selectel/pyte
COMMENT=	VTXXX-compatible terminal emulator library
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.1.7:../../devel/py-wcwidth

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
