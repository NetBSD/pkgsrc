# $NetBSD: Makefile,v 1.34 2022/06/28 11:31:37 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	5
COMMENT=	Python extension for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=	modified-bsd

# TODO: switch to PYTHON_VERSIONS_INCOMPATIBLE
#PYTHON_VERSIONS_ACCEPTED=	37 27 # 37 fails as of 1.0.0

.include "../../lang/python/pyversion.mk"

CONFIGURE_ARGS+=	--disable-perl

#.if ${_PYTHON_VERSION} == 27
#CONFIGURE_ARGS+=	--disable-python3
#.else
#CONFIGURE_ARGS+=	--disable-python
#.endif
CONFIGURE_ARGS+=	--with-python-prefix=${PREFIX}
CONFIGURE_ENV+=		PYVERSSUFFIX=${PYVERSSUFFIX}

BUILD_DIRS=		src/api/python

PY_PATCHPLIST=		yes

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
