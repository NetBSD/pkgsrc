# $NetBSD: buildlink3.mk,v 1.23 2026/01/07 08:48:27 wiz Exp $

BUILDLINK_TREE+=	rtmpdump

.if !defined(RTMPDUMP_BUILDLINK3_MK)
RTMPDUMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rtmpdump+=	rtmpdump>=2.3
BUILDLINK_ABI_DEPENDS.rtmpdump+=	rtmpdump>=2.6.0.0.6f6bb1353fc84f4cc37138baa99f586750028a01nb1
BUILDLINK_PKGSRCDIR.rtmpdump?=		../../net/rtmpdump

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif	# RTMPDUMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-rtmpdump
