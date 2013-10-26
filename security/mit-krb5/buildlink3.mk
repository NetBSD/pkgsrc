# $NetBSD: buildlink3.mk,v 1.14 2013/10/26 05:28:43 richard Exp $

BUILDLINK_TREE+=	mit-krb5

.if !defined(MIT_KRB5_BUILDLINK3_MK)
MIT_KRB5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mit-krb5+=	mit-krb5>=1.4
BUILDLINK_PKGSRCDIR.mit-krb5?=		../../security/mit-krb5
.endif # MIT_KRB5_BUILDLINK3_MK

BUILDLINK_TREE+=	-mit-krb5
