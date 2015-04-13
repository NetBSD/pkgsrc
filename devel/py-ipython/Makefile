# $NetBSD: Makefile,v 1.11 2015/04/13 23:12:41 rodent Exp $

DISTNAME=	ipython-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel lang
MASTER_SITES=	https://pypi.python.org/packages/source/i/ipython/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-zmq>=14.0.1:../../net/py-zmq

PYTHON_SELF_CONFLICT=	yes
# requires Python >= 2.7.2 or >= 3.3.0

USE_LANGUAGES=	# none

REPLACE_PYTHON=	*/*/*.py */*/*/*.py

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
