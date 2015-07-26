# $NetBSD: Makefile,v 1.8 2015/07/26 22:47:34 wiz Exp $

DISTNAME=	mock-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/m/mock/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/pypi/mock
COMMENT=	Python testing framework
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-pbr>=0.11:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-six>=1.7:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
