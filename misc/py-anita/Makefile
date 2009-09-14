# $NetBSD: Makefile,v 1.3 2009/09/14 19:21:38 gson Exp $
#

DISTNAME=	anita-1.6
PKGREVISION=	1
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
