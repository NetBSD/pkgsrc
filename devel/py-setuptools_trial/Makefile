# $NetBSD: Makefile,v 1.1.1.1 2010/07/24 13:18:59 gdt Exp $
#

DISTNAME=	setuptools_trial-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/s/setuptools_trial/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/packages/source/s/setuptools_trial/
COMMENT=	Setuptools plugin for Twisted-based unit tests
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DEPENDS+=       ${PYPKGPREFIX}-twisted:../../net/py-twisted

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
