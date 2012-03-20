# $NetBSD: Makefile,v 1.3 2012/03/20 22:00:10 cheusov Exp $

PKGNAME=	heirloom-cp-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build cp"

NEED_LIBSOCKET=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
