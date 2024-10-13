# $NetBSD: Makefile,v 1.5 2024/10/13 10:19:02 wiz Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
SYSLOG_MOD=		python
SYSLOG_MOD_TARGET=	mod-python
COMMENT=		Syslog-ng Python module
GITHUB_PROJECT=		syslog-ng

TOOL_DEPENDS+=		${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--with-python=${PYVERSSUFFIX}

INSTALL_TARGET+=	install-pylib
PY_PATCHPLIST=		yes

INSTALLATION_DIRS+=	${PYSITELIB}
post-install:
	mv ${DESTDIR}${PREFIX}/lib/syslog-ng/python/* ${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
