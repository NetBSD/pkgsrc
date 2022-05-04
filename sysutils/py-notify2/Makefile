# $NetBSD: Makefile,v 1.2 2022/05/04 07:27:26 adam Exp $

DISTNAME=	notify2-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/notify2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/takluyver/pynotify2
COMMENT=	Python interface to DBus notifications
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-dbus-[0-9]*:../../sysutils/py-dbus

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
