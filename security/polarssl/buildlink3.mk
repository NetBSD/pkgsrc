# $NetBSD: buildlink3.mk,v 1.3 2015/03/27 23:30:42 rodent Exp $

BUILDLINK_TREE+=	polarssl

.if !defined(POLARSSL_BUILDLINK3_MK)
POLARSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polarssl+=	polarssl>=0.10.0
BUILDLINK_PKGSRCDIR.polarssl?=	../../security/polarssl

.endif # POLARSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-polarssl
