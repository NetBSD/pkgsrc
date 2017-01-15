# $NetBSD: Makefile,v 1.2 2017/01/15 13:06:04 wiz Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
SYSLOG_MOD=		python
SYSLOG_MOD_TARGET=	mod-python
COMMENT=		Syslog-ng Python module
GITHUB_PROJECT=		syslog-ng

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--with-python=${PYVERSSUFFIX}

INSTALL_TARGET+=	install-pylib
PY_PATCHPLIST=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
