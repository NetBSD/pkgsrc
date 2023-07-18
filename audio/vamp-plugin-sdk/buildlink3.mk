# $NetBSD: buildlink3.mk,v 1.8 2023/07/18 12:56:06 nia Exp $

BUILDLINK_TREE+=	vamp-plugin-sdk

.if !defined(VAMP_PLUGIN_SDK_BUILDLINK3_MK)
VAMP_PLUGIN_SDK_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++11

BUILDLINK_API_DEPENDS.vamp-plugin-sdk+=	vamp-plugin-sdk>=2.6
BUILDLINK_ABI_DEPENDS.vamp-plugin-sdk?=	vamp-plugin-sdk>=2.10.0nb3
BUILDLINK_PKGSRCDIR.vamp-plugin-sdk?=	../../audio/vamp-plugin-sdk

.include "../../audio/libsndfile/buildlink3.mk"
.endif	# VAMP_PLUGIN_SDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-vamp-plugin-sdk
