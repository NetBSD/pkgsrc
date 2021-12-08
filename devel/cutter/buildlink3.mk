# $NetBSD: buildlink3.mk,v 1.8 2021/12/08 16:01:51 adam Exp $
#

BUILDLINK_TREE+=	cutter

.if !defined(CUTTER_BUILDLINK3_MK)
CUTTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cutter+=	cutter>=1.1.3
BUILDLINK_DEPMETHOD.cutter?=	build
BUILDLINK_ABI_DEPENDS.cutter+=	cutter>=1.2.4nb31
BUILDLINK_PKGSRCDIR.cutter?=	../../devel/cutter

.include "../../devel/glib2/buildlink3.mk"
.endif	# CUTTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-cutter
