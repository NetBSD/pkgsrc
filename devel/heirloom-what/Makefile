# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:45:35 cheusov Exp $

PKGNAME=	heirloom-what-${HEIRLOOM_VER}
CATEGORIES=	textproc
LICENSE=	cddl-1.0

MAKE_FLAGS+=	SUBDIRS="build what"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
