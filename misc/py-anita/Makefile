# $NetBSD: Makefile,v 1.37 2015/05/02 07:54:11 gson Exp $

DISTNAME=	anita-1.38
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	http://www.gson.org/netbsd/anita/download/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.gson.org/netbsd/anita/
COMMENT=	Automated NetBSD Installation and Test Application
LICENSE=	isc

DEPENDS+=	cdrtools>=2.00.00.00:../../sysutils/cdrtools
DEPENDS+=	${PYPKGPREFIX}-pexpect>=2.1:../../devel/py-pexpect

USE_LANGUAGES=	#none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.34

.include "options.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
