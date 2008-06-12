# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:35 joerg Exp $
#

PKGREVISION=		1

PERDITION_COMMENT=	GDBM user database module
PERDITION_PKGNAME=	gdbm
BUILD_DIRS=		makegdbm perdition/db/gdbm

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mail/perdition/buildlink3.mk"
.include "../perdition/Makefile.common"
