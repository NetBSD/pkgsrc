# $NetBSD: Makefile,v 1.1.1.1 2011/05/27 23:28:35 cheusov Exp $

PKGNAME=	heirloom-whoami-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build whoami"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
