# $NetBSD: Makefile,v 1.1.1.1 2011/05/27 23:45:54 cheusov Exp $

PKGNAME=	heirloom-setpgrp-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build setpgrp"

NOT_FOR_PLATFORM+=	Interix-*-*

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
