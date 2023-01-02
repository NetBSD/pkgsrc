# $NetBSD: buildlink3.mk,v 1.10 2023/01/02 00:11:16 wiz Exp $

BUILDLINK_TREE+=	gssdp12

.if !defined(GSSDP12_BUILDLINK3_MK)
GSSDP12_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gssdp12+=	gssdp12>=1.2
BUILDLINK_ABI_DEPENDS.gssdp12?=	gssdp12>=1.2.2nb16
BUILDLINK_PKGSRCDIR.gssdp12?=	../../net/gssdp12

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.endif	# GSSDP12_BUILDLINK3_MK

BUILDLINK_TREE+=	-gssdp12
