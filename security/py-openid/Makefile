# $NetBSD: Makefile,v 1.2 2010/01/23 22:57:05 joerg Exp $

DISTVERS=	2.2.4
DISTNAME=	python-openid-${DISTVERS}
PKGNAME=	${PYPKGPREFIX}-openid-${DISTVERS}
CATEGORIES=	security python
MASTER_SITES=	http://www.openidenabled.com/files/python-openid/packages/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://www.openidenabled.com/openid/libraries/python/
COMMENT=	Python module for OpenID
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=	26 25

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
