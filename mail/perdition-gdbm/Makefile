# $NetBSD: Makefile,v 1.5 2011/04/22 13:44:04 obache Exp $

PKGREVISION=		1
PERDITION_COMMENT=	GDBM user database module
PERDITION_PKGNAME=	gdbm
BUILD_DIRS=		makegdbm perdition/db/gdbm

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mail/perdition/buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
