# $NetBSD: Makefile,v 1.42 2021/12/19 13:21:26 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-gdbm-${PY_DISTVERSION}
PKGREVISION=	1
CATEGORIES=	databases python

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	https://docs.python.org/3/library/dbm.html#module-dbm.gnu
COMMENT=	Python interface to gdbm - GNU database manager

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
