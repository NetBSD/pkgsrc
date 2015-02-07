# $NetBSD: Makefile,v 1.3 2015/02/07 22:06:52 tnn Exp $

DISTNAME=	SoftLayer-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/SoftLayer/softlayer/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/S/SoftLayer/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://pypi.python.org/packages/source/S/SoftLayer/
COMMENT=	SoftLayer API bindings for Python
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-prettytable>=0.7.2:../../textproc/py-prettytable
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.1:../../devel/py-docopt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
