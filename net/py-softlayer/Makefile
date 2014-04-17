# $NetBSD: Makefile,v 1.2 2014/04/17 21:17:21 imil Exp $

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
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.1:../../devel/py-docopt/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
