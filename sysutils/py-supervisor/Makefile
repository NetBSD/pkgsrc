# $NetBSD: Makefile,v 1.19 2026/02/10 08:12:39 wiz Exp $

DISTNAME=	supervisor-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/supervisor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://supervisord.org/
COMMENT=	System for controlling process state under UNIX
LICENSE=	original-bsd

DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

REPLACE_PYTHON+=	supervisor/scripts/*.py
PYTHON_SELF_CONFLICT=	yes

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-build
SUBST_MESSAGE.python=	Fixing Python path.
SUBST_FILES.python+=	supervisor/tests/fixtures/unkillable_spew.py
SUBST_FILES.python+=	supervisor/tests/fixtures/spew.py
SUBST_SED.python+=	-e "s,<<PYTHON>>,${PYTHONBIN},"

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	pre-build
SUBST_MESSAGE.varbase=	Fixing /var path.
SUBST_VARS.varbase+=	VARBASE
SUBST_FILES.varbase+=	supervisor/skel/sample.conf

FILES_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

EGDIR=			share/examples/supervisor
RCD_SCRIPTS=		supervisord
INSTALLATION_DIRS+=	${EGDIR} share/examples/rc.d
CONF_FILES+=		${EGDIR}/supervisord.conf ${PKG_SYSCONFDIR}/supervisord.conf

post-install:
.for bin in echo_supervisord_conf pidproxy supervisorctl supervisord
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor
	${INSTALL_DATA} ${WRKSRC}/supervisor/skel/sample.conf \
		${DESTDIR}${PREFIX}/share/examples/supervisor/supervisord.conf

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
