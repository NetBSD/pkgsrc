# $NetBSD: buildlink3.mk,v 1.8 2026/05/06 17:08:48 vins Exp $

BUILDLINK_TREE+=	fuse

.if !defined(FUSE_BUILDLINK3_MK)
FUSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fuse+=	fuse>=3.10
BUILDLINK_API_DEPENDS.fuse+=	fuse>=3.18.2
BUILDLINK_PKGSRCDIR.fuse?=	../../filesystems/fuse

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  include "../../filesystems/perfuse/buildlink3.mk"
.elif ${OPSYS} == "Linux"
.  include "../../devel/liburing/buildlink3.mk"
.endif

.endif # FUSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-fuse
