# $NetBSD: Makefile,v 1.2 2019/12/19 22:12:57 joerg Exp $

DISTNAME=	pyte-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyte/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://github.com/selectel/pyte
COMMENT=	VTXXX-compatible terminal emulator library
LICENSE=	gnu-lgpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.1.7:../../devel/py-wcwidth

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
