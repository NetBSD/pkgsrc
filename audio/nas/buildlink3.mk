# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:23:58 joerg Exp $

BUILDLINK_TREE+=	nas

.if !defined(NAS_BUILDLINK3_MK)
NAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nas+=	nas>=1.4.2
BUILDLINK_ABI_DEPENDS.nas+=	nas>=1.7bnb2
BUILDLINK_PKGSRCDIR.nas?=	../../audio/nas
.endif # NAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nas
