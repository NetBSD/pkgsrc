# $NetBSD: buildlink3.mk,v 1.4 2010/09/06 10:30:43 wiz Exp $

BUILDLINK_TREE+=	fuse

.if !defined(FUSEFS_BUILDLINK3_MK)
FUSEFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fuse+=	fuse>=2.5.2
BUILDLINK_PKGSRCDIR.fuse?=	../../filesystems/fuse

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
.include "../../filesystems/perfuse/buildlink3.mk"
.endif
.endif # FUSEFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-fuse
