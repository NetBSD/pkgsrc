# $NetBSD: Makefile,v 1.12 2015/06/12 11:12:19 wiz Exp $

DISTNAME=	ipython-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel lang
MASTER_SITES=	https://pypi.python.org/packages/source/i/ipython/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-zmq>=14.0.1:../../net/py-zmq

USE_LANGUAGES=	# none

REPLACE_PYTHON=	*/*/*.py */*/*/*.py

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
