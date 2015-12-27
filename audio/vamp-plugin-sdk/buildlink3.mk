# $NetBSD: buildlink3.mk,v 1.1 2015/12/27 23:35:33 kamil Exp $

BUILDLINK_TREE+=	vamp-plugin-sdk

.if !defined(VAMP_PLUGIN_SDK_BUILDLINK3_MK)
VAMP_PLUGIN_SDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vamp-plugin-sdk+=	vamp-plugin-sdk>=2.6
BUILDLINK_PKGSRCDIR.vamp-plugin-sdk?=	../../audio/vamp-plugin-sdk

.include "../../audio/libsndfile/buildlink3.mk"
.endif	# VAMP_PLUGIN_SDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-vamp-plugin-sdk
