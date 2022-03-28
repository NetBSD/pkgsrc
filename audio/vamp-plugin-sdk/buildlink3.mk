# $NetBSD: buildlink3.mk,v 1.4 2022/03/28 10:43:40 tnn Exp $

BUILDLINK_TREE+=	vamp-plugin-sdk

.if !defined(VAMP_PLUGIN_SDK_BUILDLINK3_MK)
VAMP_PLUGIN_SDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vamp-plugin-sdk+=	vamp-plugin-sdk>=2.6
BUILDLINK_ABI_DEPENDS.vamp-plugin-sdk?=	vamp-plugin-sdk>=2.10.0nb1
BUILDLINK_PKGSRCDIR.vamp-plugin-sdk?=	../../audio/vamp-plugin-sdk

# C++11
GCC_REQD+=	4.7

.include "../../audio/libsndfile/buildlink3.mk"
.endif	# VAMP_PLUGIN_SDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-vamp-plugin-sdk
