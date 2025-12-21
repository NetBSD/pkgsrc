# $NetBSD: buildlink3.mk,v 1.3 2025/12/21 12:22:23 markd Exp $

BUILDLINK_TREE+=	kimageannotator

.if !defined(KIMAGEANNOTATOR_BUILDLINK3_MK)
KIMAGEANNOTATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kimageannotator+=	kimageannotator>=0.6.0
BUILDLINK_ABI_DEPENDS.kimageannotator?=	kimageannotator>=0.7.1nb8
BUILDLINK_PKGSRCDIR.kimageannotator?=	../../graphics/kimageannotator

.include "../../graphics/kcolorpicker/buildlink3.mk"
.endif	# KIMAGEANNOTATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-kimageannotator
