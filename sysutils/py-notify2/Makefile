# $NetBSD: Makefile,v 1.1 2022/03/10 23:48:02 gutteridge Exp $

DISTNAME=	notify2-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	https://files.pythonhosted.org/packages/aa/e8/d4b335aa739dc299a77766ecc5f1972d1de1993524aa94acef3219bba315/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/takluyver/pynotify2
COMMENT=	Python interface to DBus notifications
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-dbus-[0-9]*:../../sysutils/py-dbus

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
