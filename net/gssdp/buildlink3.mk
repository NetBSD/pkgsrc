# $NetBSD: buildlink3.mk,v 1.46 2024/11/01 12:53:52 wiz Exp $

BUILDLINK_TREE+=	gssdp

.if !defined(GSSDP_BUILDLINK3_MK)
GSSDP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gssdp+=	gssdp>=1.6
BUILDLINK_ABI_DEPENDS.gssdp+=	gssdp>=1.6.2nb5
BUILDLINK_PKGSRCDIR.gssdp?=	../../net/gssdp

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.endif	# GSSDP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gssdp
