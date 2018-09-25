# $NetBSD: buildlink3.mk,v 1.7 2018/09/25 09:25:45 wiz Exp $

BUILDLINK_TREE+=	rtmpdump

.if !defined(RTMPDUMP_BUILDLINK3_MK)
RTMPDUMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rtmpdump+=	rtmpdump>=2.3
BUILDLINK_ABI_DEPENDS.rtmpdump+=	rtmpdump>=2.4.0.0
BUILDLINK_PKGSRCDIR.rtmpdump?=		../../net/rtmpdump

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif	# RTMPDUMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-rtmpdump
