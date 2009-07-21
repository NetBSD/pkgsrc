# $NetBSD: Makefile,v 1.1.1.1 2009/07/21 13:26:49 roy Exp $

DISTVERS=	2.2.4
DISTNAME=	python-openid-${DISTVERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	http://www.openidenabled.com/files/python-openid/packages/	
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://www.openidenabled.com/openid/libraries/python/
COMMENT=	Python module for OpenID

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=	25

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
