# $NetBSD: Makefile,v 1.24 2013/04/23 17:16:45 gson Exp $
#

DISTNAME=	anita-1.30
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	http://www.gson.org/netbsd/anita/download/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.gson.org/netbsd/anita/
COMMENT=	Automated NetBSD Installation and Test Application
LICENSE=	isc

DEPENDS+=	qemu>=0.12.3nb2:../../emulators/qemu0
DEPENDS+=	cdrtools>=2.00.00.00:../../sysutils/cdrtools
DEPENDS+=	${PYPKGPREFIX}-pexpect>=2.1:../../devel/py-pexpect

USE_LANGUAGES=	#none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
