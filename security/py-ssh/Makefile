# $NetBSD: Makefile,v 1.1.1.1 2012/02/12 15:05:04 gls Exp $
#
DISTNAME=	ssh-${VERSION}
PKGNAME=	${PYPKGPREFIX}-ssh-${VERSION}
CATEGORIES=	security
MASTER_SITES=	http://pypi.python.org/packages/source/s/ssh/
VERSION=	1.7.12

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/ssh/
COMMENT=	This is a library for making SSH2 connections (client or server)
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-crypto>=2.1:../../security/py-crypto
PYDISTUTILSPKG= yes

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
