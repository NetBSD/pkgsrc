# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:17:44 cheusov Exp $

PKGNAME=	heirloom-sed-${HEIRLOOM_VER}
CATEGORIES=	textproc lang
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build sed"

NEED_LIBUXRE=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../devel/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
