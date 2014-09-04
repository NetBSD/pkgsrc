# $NetBSD: buildlink3.mk,v 1.1 2014/09/04 19:53:36 fhajny Exp $

BUILDLINK_TREE+=	liblognorm

.if !defined(LIBLOGNORM_BUILDLINK3_MK)
LIBLOGNORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblognorm+=	liblognorm>=1.0.0
BUILDLINK_PKGSRCDIR.liblognorm?=	../../sysutils/liblognorm

.endif # LIBLOGNORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblognorm
