# $NetBSD: buildlink3.mk,v 1.1 2026/05/09 20:01:32 vins Exp $

BUILDLINK_TREE+=	fuse3

.if !defined(FUSE3_BUILDLINK3_MK)
FUSE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fuse3+=	fuse3>=3.10
BUILDLINK_API_DEPENDS.fuse3+=	fuse3>=3.18.2
BUILDLINK_PKGSRCDIR.fuse3?=	../../filesystems/fuse3

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  include "../../filesystems/perfuse/buildlink3.mk"
.elif ${OPSYS} == "Linux"
.  include "../../devel/liburing/buildlink3.mk"
.endif

.endif # FUSE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-fuse3
