# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:01 joerg Exp $

BUILDLINK_TREE+=	meanwhile

.if !defined(MEANWHILE_BUILDLINK3_MK)
MEANWHILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.meanwhile+=	meanwhile>=1.0.2
BUILDLINK_PKGSRCDIR.meanwhile?=	../../chat/meanwhile
.endif # MEANWHILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-meanwhile
