# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 01:01:46 cheusov Exp $

PKGNAME=	heirloom-awk-${HEIRLOOM_VER}
CATEGORIES=	textproc lang
LICENSE=	gnu-gpl-v2 AND original-bsd

MAKE_FLAGS+=	SUBDIRS="build oawk nawk"

NEED_LIBUXRE=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../devel/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
