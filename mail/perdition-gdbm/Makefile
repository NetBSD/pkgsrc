# $NetBSD: Makefile,v 1.4 2010/06/02 12:50:04 adam Exp $

PERDITION_COMMENT=	GDBM user database module
PERDITION_PKGNAME=	gdbm
BUILD_DIRS=		makegdbm perdition/db/gdbm

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mail/perdition/buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
