# $NetBSD: Makefile,v 1.28 2014/01/25 10:30:14 wiz Exp $

DISTNAME=	anita-1.31
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

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 1.31

.include "options.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
