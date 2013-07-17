# $NetBSD: buildlink3.mk,v 1.13 2013/07/17 12:24:41 obache Exp $

BUILDLINK_TREE+=	physfs

.if !defined(PHYSFS_BUILDLINK3_MK)
PHYSFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.physfs+=	physfs>=1.0.0
BUILDLINK_ABI_DEPENDS.physfs+=	physfs>=1.0.1nb1
BUILDLINK_PKGSRCDIR.physfs?=	../../devel/physfs

.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # PHYSFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-physfs
