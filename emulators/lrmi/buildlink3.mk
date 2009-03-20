# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:33 joerg Exp $

BUILDLINK_TREE+=	lrmi

.if !defined(LRMI_BUILDLINK3_MK)
LRMI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lrmi+=	lrmi>=0.8nb1
BUILDLINK_PKGSRCDIR.lrmi?=	../../emulators/lrmi
.endif # LRMI_BUILDLINK3_MK

BUILDLINK_TREE+=	-lrmi
