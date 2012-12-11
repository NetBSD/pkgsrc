# $NetBSD: buildlink3.mk,v 1.1 2012/12/11 23:29:27 gdt Exp $

BUILDLINK_TREE+=	polarssl

.if !defined(POLARSSL_BUILDLINK3_MK)
POLARSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polarssl+=	polarssl>=0.10.0
BUILDLINK_PKGSRCDIR.polarssl?=	../../security/polarssl

.endif # POLARSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-polarssl
