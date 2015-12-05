# $NetBSD: Makefile,v 1.3 2015/12/05 21:25:33 adam Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
COMMENT=		Python extension for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=		modified-bsd

CONFIGURE_ARGS+=	--with-python-prefix=${PREFIX}

BUILD_DIRS=		src/api/python

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.55

PY_PATCHPLIST=		yes

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
