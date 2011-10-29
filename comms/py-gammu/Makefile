# $NetBSD: Makefile,v 1.2 2011/10/29 13:22:16 obache Exp $
#

.include "../../comms/gammu/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
COMMENT=	Python bindings for gammu

DISTINFO_FILE=	${.CURDIR}/../../comms/gammu/distinfo
PATCHDIR=	${.CURDIR}/../../comms/gammu/patches

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=		pkg-config
CONFLICTS=		gammu<=1.24.0

PYSETUPSUBDIR=		python
PYSETUPBUILDTARGET=	build_ext
PYSETUPBUILDARGS=	--gammu-incs=${BUILDLINK_PREFIX.gammu}/include/gammu
PYSETUPBUILDARGS+=	--gammu-libs=${BUILDLINK_PREFIX.gammu}/lib

EGG_NAME=	python_${DISTNAME}

.include "../../lang/python/distutils.mk"
.include "../../comms/gammu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
