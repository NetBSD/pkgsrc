# $NetBSD: Makefile,v 1.15 2018/08/16 18:54:39 adam Exp $

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		5
COMMENT=		Python extension for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=		modified-bsd

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py27"
CONFIGURE_ARGS+=	--disable-python3
CONFIGURE_ARGS+=	--with-python-prefix=${PREFIX}
.else
CONFIGURE_ARGS+=	--disable-python2
CONFIGURE_ARGS+=	--with-python3-prefix=${PREFIX}
.endif

BUILD_DIRS=		src/api/python

PY_PATCHPLIST=		yes

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
