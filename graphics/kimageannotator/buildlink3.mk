# $NetBSD: buildlink3.mk,v 1.1 2022/09/29 00:09:28 markd Exp $

BUILDLINK_TREE+=	kimageannotator

.if !defined(KIMAGEANNOTATOR_BUILDLINK3_MK)
KIMAGEANNOTATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kimageannotator+=	kimageannotator>=0.6.0
BUILDLINK_PKGSRCDIR.kimageannotator?=	../../graphics/kimageannotator

.include "../../graphics/kcolorpicker/buildlink3.mk"
.endif	# KIMAGEANNOTATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-kimageannotator
