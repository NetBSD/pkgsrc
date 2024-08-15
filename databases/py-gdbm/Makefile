# $NetBSD: Makefile,v 1.45 2024/08/15 22:04:25 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-gdbm-${PY_DISTVERSION}
PKGREVISION=	1
CATEGORIES=	databases python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.python.org/3/library/dbm.html#module-dbm.gnu
COMMENT=	Python interface to gdbm - GNU database manager

# srcdist.mk needs to be adapted for distutils removal in 3.12
PYTHON_VERSIONS_ACCEPTED=	311 310 27

.include "../../lang/python/pyversion.mk"
.if !empty(PYPKGPREFIX:Mpy2?)
GDBM_MODNAME=	gdbm
.else
GDBM_MODNAME=	_gdbm
.endif

PYDISTUTILSPKG=		yes

PY_SETUP_SUBST+=	GDBMPREFIX=${BUILDLINK_PREFIX.gdbm}
PY_SETUP_SUBST+=	GDBM_MODNAME=${GDBM_MODNAME}
PLIST_SUBST+=		GDBM_MODNAME=${GDBM_MODNAME}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
