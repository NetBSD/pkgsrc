# $NetBSD: Makefile,v 1.2 2022/01/19 17:54:37 wiz Exp $

DISTNAME=	mox-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mox/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/pymox/
COMMENT=	Mock object framework for Python
LICENSE=	apache-2.0

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} mox_test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
