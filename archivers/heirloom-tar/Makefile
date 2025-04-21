# $NetBSD: Makefile,v 1.3 2025/04/21 16:18:05 wiz Exp $

PKGNAME=	heirloom-tar-${HEIRLOOM_VER}
CATEGORIES=	sysutils
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build tar"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
