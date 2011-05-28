# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:30:35 cheusov Exp $

PKGNAME=	heirloom-calendar-${HEIRLOOM_VER}
CATEGORIES=	misc time
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build calendar"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
