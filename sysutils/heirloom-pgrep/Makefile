# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:19 cheusov Exp $

PKGNAME=	heirloom-pgrep-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build pgrep"

NEED_LIBUXRE=	1
NEED_LIBKVM=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../devel/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
