# $NetBSD: Makefile,v 1.7 2016/10/07 18:25:41 adam Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
COMMENT=		Python extension for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=		modified-bsd

CONFIGURE_ARGS+=	--with-python-prefix=${PREFIX}

BUILD_DIRS=		src/api/python

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.55

PY_PATCHPLIST=		yes

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
