# $NetBSD: Makefile,v 1.6 2011/08/23 13:06:50 obache Exp $

PKGREVISION=		2
PERDITION_COMMENT=	GDBM user database module
PERDITION_PKGNAME=	gdbm
BUILD_DIRS=		makegdbm perdition/db/gdbm

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mail/perdition/buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
