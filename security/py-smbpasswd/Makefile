# $NetBSD: Makefile,v 1.5 2009/09/07 19:02:14 joerg Exp $
#

DISTNAME=	py-smbpasswd-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	security
MASTER_SITES=	http://barryp.org/static/software/download/py-smbpasswd/1.0.1/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://barryp.org/software/py-smbpasswd/
COMMENT=	Python SMB Password Hash Generator

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=	25 24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
