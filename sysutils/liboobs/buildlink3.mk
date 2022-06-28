# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:35:57 wiz Exp $

BUILDLINK_TREE+=	liboobs

.if !defined(LIBOOBS_BUILDLINK3_MK)
LIBOOBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboobs+=	liboobs>=2.22.0
BUILDLINK_ABI_DEPENDS.liboobs?=	liboobs>=2.22.2nb16
BUILDLINK_PKGSRCDIR.liboobs?=	../../sysutils/liboobs
.endif # LIBOOBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboobs
