# $NetBSD: Makefile,v 1.1 2018/02/03 14:59:20 bsiegert Exp $

DISTNAME=	mox-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mox/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/pymox/
COMMENT=	Mox is a mock object framework for Python
LICENSE=	apache-2.0

PYDISTUTILSPKG=	yes

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} mox_test.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
