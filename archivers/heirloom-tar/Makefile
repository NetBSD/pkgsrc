# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:48:39 cheusov Exp $

PKGNAME=	heirloom-tar-${HEIRLOOM_VER}
CATEGORIES=	sysutils
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build tar"

NOT_FOR_PLATFORM+=	Interix-*-*

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
