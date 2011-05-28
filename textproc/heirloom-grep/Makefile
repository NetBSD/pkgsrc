# $NetBSD: Makefile,v 1.3 2011/05/28 11:42:05 cheusov Exp $

PKGNAME=	heirloom-grep-${HEIRLOOM_VER}
CATEGORIES=	textproc sysutils

MAKE_FLAGS+=	SUBDIRS="build grep"

NEED_LIBUXRE=	1
USE_TOOLS=	yacc

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../devel/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
