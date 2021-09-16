# $NetBSD: Makefile,v 1.3 2021/09/16 09:22:46 wiz Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
SYSLOG_MOD=		python
SYSLOG_MOD_TARGET=	mod-python
COMMENT=		Syslog-ng Python module
GITHUB_PROJECT=		syslog-ng

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--with-python=${PYVERSSUFFIX}

INSTALL_TARGET+=	install-pylib
PY_PATCHPLIST=		yes

INSTALLATION_DIRS+=	${PYSITELIB}
post-install:
	mv ${DESTDIR}${PREFIX}/lib/syslog-ng/python/* ${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
