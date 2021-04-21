# $NetBSD: buildlink3.mk,v 1.11 2021/04/21 13:24:14 adam Exp $

BUILDLINK_TREE+=	rtmpdump

.if !defined(RTMPDUMP_BUILDLINK3_MK)
RTMPDUMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rtmpdump+=	rtmpdump>=2.3
BUILDLINK_ABI_DEPENDS.rtmpdump+=	rtmpdump>=2.4.0.0.fa8646daeb19dfd12c181f7d19de708d623704c0nb4
BUILDLINK_PKGSRCDIR.rtmpdump?=		../../net/rtmpdump

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif	# RTMPDUMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-rtmpdump
