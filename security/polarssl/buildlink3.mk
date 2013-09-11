# $NetBSD: buildlink3.mk,v 1.2 2013/09/11 13:17:03 obache Exp $

BUILDLINK_TREE+=	polarssl

.if !defined(POLARSSL_BUILDLINK3_MK)
POLARSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polarssl+=	polarssl>=0.10.0
BUILDLINK_DEPMETHOD.polarssl?=		build
BUILDLINK_PKGSRCDIR.polarssl?=	../../security/polarssl

.endif # POLARSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-polarssl
