# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:30 joerg Exp $

BUILDLINK_TREE+=	sysexits

.if !defined(SYSEXITS_BUILDLINK3_MK)
SYSEXITS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sysexits+=	sysexits>=1.1
BUILDLINK_DEPMETHOD.sysexits?=	build
BUILDLINK_PKGSRCDIR.sysexits?=	../../devel/sysexits
.endif # SYSEXITS_BUILDLINK3_MK

BUILDLINK_TREE+=	-sysexits
