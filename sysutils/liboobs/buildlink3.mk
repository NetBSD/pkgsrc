# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:25 joerg Exp $

BUILDLINK_TREE+=	liboobs

.if !defined(LIBOOBS_BUILDLINK3_MK)
LIBOOBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboobs+=	liboobs>=2.22.0
BUILDLINK_PKGSRCDIR.liboobs?=	../../sysutils/liboobs
.endif # LIBOOBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboobs
