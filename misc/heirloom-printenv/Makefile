# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 09:56:56 cheusov Exp $

PKGNAME=	heirloom-printenv-${HEIRLOOM_VER}
CATEGORIES=	misc

MAKE_FLAGS+=	SUBDIRS="build printenv"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
