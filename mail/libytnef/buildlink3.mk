# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:21 rillig Exp $

BUILDLINK_TREE+=	libytnef

.if !defined(LIBYTNEF_BUILDLINK3_MK)
LIBYTNEF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libytnef+=	libytnef>=1.5
BUILDLINK_ABI_DEPENDS.libytnef?=	libytnef>=1.9.2
BUILDLINK_PKGSRCDIR.libytnef?=		../../mail/libytnef
.endif # LIBYTNEF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libytnef
