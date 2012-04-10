# $NetBSD: Makefile,v 1.21 2012/04/10 13:23:58 gson Exp $
#

DISTNAME=	anita-1.27
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	http://www.gson.org/netbsd/anita/download/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.gson.org/netbsd/anita/
COMMENT=	Automated NetBSD Installation and Test Application
LICENSE=	isc

DEPENDS+=	qemu>=0.12.3nb2:../../emulators/qemu
DEPENDS+=	cdrtools>=2.00.00.00:../../sysutils/cdrtools
DEPENDS+=	${PYPKGPREFIX}-pexpect>=2.1:../../devel/py-pexpect

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	#none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
