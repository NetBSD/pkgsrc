# $NetBSD: buildlink3.mk,v 1.8 2018/01/07 13:04:11 rillig Exp $

BUILDLINK_TREE+=	sysexits

.if !defined(SYSEXITS_BUILDLINK3_MK)
SYSEXITS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sysexits+=	sysexits>=1.1
BUILDLINK_DEPMETHOD.sysexits?=		build
BUILDLINK_PKGSRCDIR.sysexits?=		../../devel/sysexits
.endif # SYSEXITS_BUILDLINK3_MK

BUILDLINK_TREE+=	-sysexits
