# $NetBSD: Makefile,v 1.9 2015/12/01 08:01:30 fhajny Exp $

DISTNAME=	mock-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/m/mock/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/pypi/mock
COMMENT=	Python testing framework
LICENSE=	gnu-gpl-v2

.include "../../lang/python/egg.mk"

DEPENDS+=	${PYPKGPREFIX}-pbr>=0.11:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-six>=1.7:../../lang/py-six
.if ${_PYTHON_VERSION} < 33
DEPENDS+=	${PYPKGPREFIX}-funcsigs-[0-9]*:../../devel/py-funcsigs
.endif

USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
