# $NetBSD: Makefile,v 1.1 2015/11/01 19:08:22 fhajny Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
SYSLOG_MOD=		python
SYSLOG_MOD_TARGET=	mod-python
COMMENT=		Syslog-ng Python module

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--with-python=${PYVERSSUFFIX}

INSTALL_TARGET+=	install-pylib
PY_PATCHPLIST=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
