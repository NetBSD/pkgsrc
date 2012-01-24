# $NetBSD: Makefile,v 1.7 2012/01/24 09:11:07 sbd Exp $

PKGREVISION=		3
PERDITION_COMMENT=	GDBM user database module
PERDITION_PKGNAME=	gdbm
BUILD_DIRS=		makegdbm perdition/db/gdbm

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mail/perdition/buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
