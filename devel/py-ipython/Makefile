# $NetBSD: Makefile,v 1.7 2014/04/20 10:06:22 imil Exp $

DISTNAME=	ipython-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lang
MASTER_SITES=	https://pypi.python.org/packages/source/i/ipython/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect

PYTHON_SELF_CONFLICT=	yes
# requires Python >= 2.7.2 or >= 3.3.0
PYTHON_VERSIONS_INCOMPATIBLE=	26

USE_LANGUAGES=	# none

REPLACE_PYTHON=	*/*/*.py */*/*/*.py

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
