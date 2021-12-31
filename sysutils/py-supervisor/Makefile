# $NetBSD: Makefile,v 1.10 2021/12/31 13:28:23 adam Exp $

DISTNAME=	supervisor-4.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/supervisor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://supervisord.org/
COMMENT=	System for controlling process state under UNIX
LICENSE=	original-bsd

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif

REPLACE_PYTHON+=	supervisor/scripts/*.py

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-build
SUBST_MESSAGE.python=	Fixing Python path.
SUBST_FILES.python+=	supervisor/tests/fixtures/unkillable_spew.py
SUBST_FILES.python+=	supervisor/tests/fixtures/spew.py
SUBST_SED.python+=	-e "s,<<PYTHON>>,${PYTHONBIN},"

post-install:
.for bin in echo_supervisord_conf pidproxy supervisorctl supervisord
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
