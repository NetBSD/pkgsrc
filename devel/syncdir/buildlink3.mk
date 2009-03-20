# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:30 joerg Exp $

BUILDLINK_TREE+=	syncdir

.if !defined(SYNCDIR_BUILDLINK3_MK)
SYNCDIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.syncdir+=	syncdir>=1.0
BUILDLINK_ABI_DEPENDS.syncdir+=	syncdir>=1.0nb1
BUILDLINK_PKGSRCDIR.syncdir?=	../../devel/syncdir
.endif # SYNCDIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-syncdir
