# $NetBSD: buildlink3.mk,v 1.7 2021/12/08 16:02:27 adam Exp $

BUILDLINK_TREE+=	gssdp12

.if !defined(GSSDP12_BUILDLINK3_MK)
GSSDP12_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gssdp12+=	gssdp12>=1.2
BUILDLINK_ABI_DEPENDS.gssdp12?=	gssdp12>=1.2.2nb10
BUILDLINK_PKGSRCDIR.gssdp12?=	../../net/gssdp12

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.endif	# GSSDP12_BUILDLINK3_MK

BUILDLINK_TREE+=	-gssdp12
