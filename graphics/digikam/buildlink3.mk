# $NetBSD: buildlink3.mk,v 1.23 2023/04/21 12:09:13 wiz Exp $

BUILDLINK_TREE+=	digikam

.if !defined(DIGIKAM_BUILDLINK3_MK)
DIGIKAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.digikam+=	digikam>=8.0.0nb1
BUILDLINK_PKGSRCDIR.digikam?=	../../graphics/digikam

.endif	# DIGIKAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-digikam
