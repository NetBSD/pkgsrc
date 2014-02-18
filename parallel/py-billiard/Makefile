# $NetBSD: Makefile,v 1.9 2014/02/18 02:53:37 rodent Exp $

DISTNAME=	billiard-3.3.0.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	https://pypi.python.org/packages/source/b/billiard/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/celery/billiard
COMMENT=	Python multiprocessing fork with improvements and bugfixes
LICENSE=	modified-bsd

USE_LANGUAGES+=	c
REPLACE_PYTHON+=	funtests/setup.py funtests/tests/test_multiprocessing.py

PYTHON_VERSIONS_INCOMPATIBLE=	26

.include "../../lang/python/pyversion.mk"

TWO_OR_THREE=	${PYPKGPREFIX:C/([0-9])[0-9]/\1/1}
PLIST_SUBST+=	PY_VER_MAJ=${TWO_OR_THREE}

.include "../../mk/bsd.fast.prefs.mk"

PLIST_VARS+=		py2
.if ${TWO_OR_THREE} != "py3"
PLIST.py2=		yes
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
