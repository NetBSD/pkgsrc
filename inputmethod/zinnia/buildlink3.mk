# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/05/20 09:05:30 obache Exp $

BUILDLINK_TREE+=	zinnia

.if !defined(ZINNIA_BUILDLINK3_MK)
ZINNIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zinnia+=	zinnia>=0.05
BUILDLINK_PKGSRCDIR.zinnia?=	../../inputmethod/zinnia
.endif	# ZINNIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-zinnia
