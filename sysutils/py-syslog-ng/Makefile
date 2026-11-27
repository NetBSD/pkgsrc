# $NetBSD: Makefile,v 1.6 2026/11/27 11:01:43 adam Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
SYSLOG_MOD=		python
SYSLOG_MOD_TARGET=	mod-python
COMMENT=		Syslog-ng Python module
GITHUB_PROJECT=		syslog-ng

TOOL_DEPENDS+=	${PYPKGPREFIX}-build>=0:../../devel/py-build
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-installer>=0.7.0nb1:../../misc/py-installer

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--with-python=${PYVERSSUFFIX}

WHEELFILE=	${WRKSRC}/modules/python-modules/dist/*.whl
WHEEL_NAME=	syslogng-1.0
_WHEEL_INFODIR=	${WHEEL_NAME}.dist-info
PLIST_SUBST+=	WHEEL_INFODIR=${_WHEEL_INFODIR}
PY_PATCHPLIST=	yes

post-build:
	${RUN} cd ${WRKSRC}/modules/python-modules && \
	${SETENV} ${MAKE_ENV} ${TOOL_PYTHONBIN} \
		-m build --wheel --skip-dependency-check --no-isolation ${WHEEL_ARGS}

#INSTALLATION_DIRS+=	${PYSITELIB}
post-install:
	${RUN} cd ${WRKSRC}/modules/python-modules && \
	${SETENV} ${INSTALL_ENV} ${TOOL_PYTHONBIN} \
		-m installer --destdir ${DESTDIR} \
		--prefix ${PREFIX} ${WHEELFILE}

.include "../../lang/python/extension.mk"
#.include "../../lang/python/wheel.mk"
.if ${PYTHON_VERSION} >= 313
.include "../../mk/atomic64.mk"
.endif
.include "../../mk/bsd.pkg.mk"
