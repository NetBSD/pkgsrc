# $NetBSD: Makefile,v 1.7 2010/04/13 12:22:27 gson Exp $
#

DISTNAME=	anita-1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	http://www.gson.org/netbsd/anita/download/

PYDISTUTILSPKG= yes
DEPENDS+=	qemu>=0.9.0:../../emulators/qemu
DEPENDS+=	cdrtools>=2.00.00.00:../../sysutils/cdrtools

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.gson.org/netbsd/anita/
COMMENT=	Automated NetBSD Installation and Test Application

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/extension.mk"
.include "../../devel/py-pexpect/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
