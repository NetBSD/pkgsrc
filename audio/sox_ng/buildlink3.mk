# $NetBSD: buildlink3.mk,v 1.1 2025/07/03 15:46:59 wiz Exp $

BUILDLINK_TREE+=	sox_ng

.if !defined(SOX_NG_BUILDLINK3_MK)
SOX_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sox_ng+=	sox_ng>=14.6.0.1
BUILDLINK_PKGSRCDIR.sox_ng?=	../../audio/sox_ng

.endif	# SOX_NG_BUILDLINK3_MK

BUILDLINK_TREE+=	-sox_ng
