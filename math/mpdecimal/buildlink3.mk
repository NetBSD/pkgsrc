# $NetBSD: buildlink3.mk,v 1.1 2024/12/24 10:52:58 wiz Exp $

BUILDLINK_TREE+=	mpdecimal

.if !defined(MPDECIMAL_BUILDLINK3_MK)
MPDECIMAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpdecimal+=	mpdecimal>=4.0.0
BUILDLINK_PKGSRCDIR.mpdecimal?=		../../math/mpdecimal
.endif	# MPDECIMAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpdecimal
