# $NetBSD: Makefile,v 1.41 2020/01/08 13:44:41 joerg Exp $

PKGNAME=	${PYPKGPREFIX}-gdbm-${PY_DISTVERSION}
PKGREVISION=	1
CATEGORIES=	databases python

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	https://docs.python.org/3/library/dbm.html#module-dbm.gnu
COMMENT=	Python interface to gdbm - GNU database manager

.include "../../lang/python/pyversion.mk"
.if !empty(PYPKGPREFIX:Mpy3?)
GDBM_MODNAME=	_gdbm
.else
GDBM_MODNAME=	gdbm
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
