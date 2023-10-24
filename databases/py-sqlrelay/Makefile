# $NetBSD: Makefile,v 1.38 2023/10/24 22:08:38 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
COMMENT=	Python extension for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=	modified-bsd

CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--with-python-prefix=${PREFIX}
CONFIGURE_ENV+=		PYVERSSUFFIX=${PYVERSSUFFIX}

BUILD_DIRS=		src/api/python

PY_PATCHPLIST=		yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
