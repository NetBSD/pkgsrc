# $NetBSD: Makefile,v 1.3 2026/01/26 09:52:54 wiz Exp $

DISTNAME=	mox-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mox/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://code.google.com/archive/p/pymox/
COMMENT=	Mock object framework for Python
LICENSE=	apache-2.0

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} mox_test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
