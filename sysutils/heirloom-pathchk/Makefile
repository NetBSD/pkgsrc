# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:19 cheusov Exp $

PKGNAME=	heirloom-pathchk-${HEIRLOOM_VER}
CATEGORIES=	sysutils misc

MAKE_FLAGS+=	SUBDIRS="build pathchk"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
