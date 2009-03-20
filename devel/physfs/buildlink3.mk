# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:26 joerg Exp $

BUILDLINK_TREE+=	physfs

.if !defined(PHYSFS_BUILDLINK3_MK)
PHYSFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.physfs+=	physfs>=1.0.0
BUILDLINK_ABI_DEPENDS.physfs+=	physfs>=1.0.1
BUILDLINK_PKGSRCDIR.physfs?=	../../devel/physfs

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # PHYSFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-physfs
