# $NetBSD: buildlink3.mk,v 1.52 2026/09/02 19:03:54 wiz Exp $

BUILDLINK_TREE+=	gssdp

.if !defined(GSSDP_BUILDLINK3_MK)
GSSDP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gssdp+=	gssdp>=1.6
BUILDLINK_ABI_DEPENDS.gssdp+=	gssdp>=1.6.6nb1
BUILDLINK_PKGSRCDIR.gssdp?=	../../net/gssdp

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.endif	# GSSDP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gssdp
