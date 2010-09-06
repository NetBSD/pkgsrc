# $NetBSD: buildlink3.mk,v 1.5 2010/09/06 12:13:30 wiz Exp $

BUILDLINK_TREE+=	fuse

.if !defined(FUSE_BUILDLINK3_MK)
FUSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fuse+=	fuse>=2.5.2
BUILDLINK_PKGSRCDIR.fuse?=	../../filesystems/fuse

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
.include "../../filesystems/perfuse/buildlink3.mk"
.endif
.endif # FUSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-fuse
