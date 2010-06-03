# $NetBSD: Makefile,v 1.5.6.1 2010/06/03 08:21:03 spz Exp $
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
PYTHON_VERSIONS_ACCEPTED=	26 25 24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
