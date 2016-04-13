# $NetBSD: Makefile,v 1.11 2016/04/13 17:57:07 wiz Exp $

DISTNAME=	mock-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/m/mock/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/pypi/mock
COMMENT=	Python testing framework
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-pbr>=0.11:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-six>=1.7:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2

.include "../../lang/python/egg.mk"

.if ${_PYTHON_VERSION} < 33
DEPENDS+=	${PYPKGPREFIX}-funcsigs-[0-9]*:../../devel/py-funcsigs
.endif

USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
