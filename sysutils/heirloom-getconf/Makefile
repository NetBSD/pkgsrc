# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 00:48:27 cheusov Exp $

PKGNAME=	heirloom-getconf-${HEIRLOOM_VER}
CATEGORIES=	sysutils
LICENSE=	cddl-1.0

MAKE_FLAGS+=	SUBDIRS="build getconf"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
