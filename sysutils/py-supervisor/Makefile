# $NetBSD: Makefile,v 1.3 2017/07/25 08:17:08 adam Exp $

DISTNAME=	supervisor-3.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=s/supervisor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://supervisord.org/
COMMENT=	System for controlling process state under UNIX
LICENSE=	original-bsd

DEPENDS+=	${PYPKGPREFIX}-meld3>=0.6.5:../../www/py-meld3
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

# as of 3.3.1, explicitly only supports 2.x
PYTHON_VERSIONS_ACCEPTED=	27

REPLACE_PYTHON+=	supervisor/scripts/*.py
SUBST_CLASSES+=		python
SUBST_SED.python+=	-e "s,<<PYTHON>>,${PYTHONBIN},"
SUBST_FILES.python+=	supervisor/tests/fixtures/*.py
SUBST_MESSAGE.python=	Fixing path to python.
SUBST_STAGE.python=	pre-build

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
