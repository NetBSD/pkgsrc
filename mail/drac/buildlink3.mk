# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:54 joerg Exp $

BUILDLINK_TREE+=	drac

.if !defined(DRAC_BUILDLINK3_MK)
DRAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.drac+=	drac>=1.10
BUILDLINK_PKGSRCDIR.drac?=	../../mail/drac
BUILDLINK_DEPMETHOD.drac?=	build
.endif # DRAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-drac
