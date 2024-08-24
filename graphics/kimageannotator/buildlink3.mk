# $NetBSD: buildlink3.mk,v 1.2 2024/08/24 04:24:47 markd Exp $

BUILDLINK_TREE+=	kimageannotator

.if !defined(KIMAGEANNOTATOR_BUILDLINK3_MK)
KIMAGEANNOTATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kimageannotator+=	kimageannotator>=0.6.0
BUILDLINK_ABI_DEPENDS.kimageannotator?=	kimageannotator>=0.7.1
BUILDLINK_PKGSRCDIR.kimageannotator?=	../../graphics/kimageannotator

.include "../../graphics/kcolorpicker/buildlink3.mk"
.endif	# KIMAGEANNOTATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-kimageannotator
