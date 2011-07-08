# $NetBSD: buildlink3.mk,v 1.12 2011/07/08 09:59:28 adam Exp $

BUILDLINK_TREE+=	mit-krb5

.if !defined(MIT_KRB5_BUILDLINK3_MK)
MIT_KRB5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mit-krb5+=	mit-krb5>=1.8
BUILDLINK_ABI_DEPENDS.mit-krb5+=	mit-krb5>=1.8
BUILDLINK_PKGSRCDIR.mit-krb5?=		../../security/mit-krb5
.endif # MIT_KRB5_BUILDLINK3_MK

BUILDLINK_TREE+=	-mit-krb5
