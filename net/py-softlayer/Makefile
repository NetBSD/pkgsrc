# $NetBSD: Makefile,v 1.4 2016/06/08 17:43:37 wiz Exp $

DISTNAME=	SoftLayer-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/SoftLayer/softlayer/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SoftLayer/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	${MASTER_SITE_PYPI:=S/SoftLayer/}
COMMENT=	SoftLayer API bindings for Python
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-prettytable>=0.7.2:../../textproc/py-prettytable
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.1:../../devel/py-docopt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
