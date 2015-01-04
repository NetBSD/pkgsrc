# $NetBSD: Makefile,v 1.4 2015/01/04 09:21:40 dholland Exp $

PKGNAME=	heirloom-time-${HEIRLOOM_VER}
CATEGORIES=	misc time

MAKE_FLAGS+=	SUBDIRS="build time"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../mk/bsd.prefs.mk"
PLIST_VARS+=	ptime
.if ${OPSYS} == "Linux"
PLIST.ptime=	yes
.endif

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
