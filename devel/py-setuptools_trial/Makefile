# $NetBSD: Makefile,v 1.6 2014/01/25 10:30:05 wiz Exp $

DISTNAME=	setuptools_trial-0.5.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/s/setuptools_trial/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/pypi/setuptools_trial/
COMMENT=	Setuptools plugin for Twisted-based unit tests
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=       ${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
