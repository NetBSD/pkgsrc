# $NetBSD: Makefile,v 1.15 2023/07/03 13:04:57 wiz Exp $

DISTNAME=	supervisor-4.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/supervisor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://supervisord.org/
COMMENT=	System for controlling process state under UNIX
LICENSE=	original-bsd

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	supervisor/scripts/*.py

USE_PKG_RESOURCES=	yes

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
