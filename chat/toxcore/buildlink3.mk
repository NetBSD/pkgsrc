# $NetBSD: buildlink3.mk,v 1.5 2024/01/22 13:16:56 ryoon Exp $

BUILDLINK_TREE+=	toxcore

.if !defined(TOXCORE_BUILDLINK3_MK)
TOXCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.toxcore+=	toxcore>=0.2.4
BUILDLINK_ABI_DEPENDS.toxcore+=	toxcore>=0.2.18nb2
BUILDLINK_PKGSRCDIR.toxcore?=	../../chat/toxcore

.include "../../audio/libopus/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.endif	# TOXCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-toxcore
