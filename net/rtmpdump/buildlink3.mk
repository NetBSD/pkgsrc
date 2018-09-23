# $NetBSD: buildlink3.mk,v 1.6 2018/09/23 21:09:32 wiz Exp $

BUILDLINK_TREE+=	rtmpdump

.if !defined(RTMPDUMP_BUILDLINK3_MK)
RTMPDUMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rtmpdump+=	rtmpdump>=2.3
BUILDLINK_ABI_DEPENDS.rtmpdump+=	rtmpdump>=2.4nb3
BUILDLINK_PKGSRCDIR.rtmpdump?=		../../net/rtmpdump

.endif	# RTMPDUMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-rtmpdump
