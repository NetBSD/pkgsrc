# $NetBSD: buildlink3.mk,v 1.3 2022/07/04 08:13:37 wiz Exp $

BUILDLINK_TREE+=	openipmi

.if !defined(OPENIPMI_BUILDLINK3_MK)
OPENIPMI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openipmi+=	openipmi>=2.0.29
BUILDLINK_ABI_DEPENDS.openipmi?=	openipmi>=2.0.29nb1
BUILDLINK_PKGSRCDIR.openipmi?=		../../sysutils/openipmi

.include "../../devel/popt/buildlink3.mk"
.endif # OPENIPMI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openipmi
