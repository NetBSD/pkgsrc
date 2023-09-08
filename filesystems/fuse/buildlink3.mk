# $NetBSD: buildlink3.mk,v 1.7 2023/09/08 06:01:04 vins Exp $

BUILDLINK_TREE+=	fuse

.if !defined(FUSE_BUILDLINK3_MK)
FUSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fuse+=	fuse>=2.5.2
BUILDLINK_ABI_DEPENDS.fuse+=	fuse>=2.9.9nb1
BUILDLINK_PKGSRCDIR.fuse?=	../../filesystems/fuse

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
.include "../../filesystems/perfuse/buildlink3.mk"
.endif
.endif # FUSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-fuse
