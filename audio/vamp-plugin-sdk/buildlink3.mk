# $NetBSD: buildlink3.mk,v 1.3 2021/01/18 09:34:30 nia Exp $

BUILDLINK_TREE+=	vamp-plugin-sdk

.if !defined(VAMP_PLUGIN_SDK_BUILDLINK3_MK)
VAMP_PLUGIN_SDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vamp-plugin-sdk+=	vamp-plugin-sdk>=2.6
BUILDLINK_ABI_DEPENDS.vamp-plugin-sdk?=	vamp-plugin-sdk>=2.9.0nb1
BUILDLINK_PKGSRCDIR.vamp-plugin-sdk?=	../../audio/vamp-plugin-sdk

# C++11
GCC_REQD+=	4.7

.include "../../audio/libsndfile/buildlink3.mk"
.endif	# VAMP_PLUGIN_SDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-vamp-plugin-sdk
