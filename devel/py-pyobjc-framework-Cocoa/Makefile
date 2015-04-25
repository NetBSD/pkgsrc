# $NetBSD: Makefile,v 1.1 2015/04/25 10:42:24 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-Cocoa-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyobjc-framework-Cocoa/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/pyobjc/
COMMENT=	Bridge between Python and Objective-C (Cocoa framework)
LICENSE=	mit

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
