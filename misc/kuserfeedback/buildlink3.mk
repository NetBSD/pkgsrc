# $NetBSD: buildlink3.mk,v 1.1 2024/02/06 02:58:48 markd Exp $

BUILDLINK_TREE+=	kuserfeedback

.if !defined(KUSERFEEDBACK_BUILDLINK3_MK)
KUSERFEEDBACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kuserfeedback+=	kuserfeedback>=1.3.0
BUILDLINK_PKGSRCDIR.kuserfeedback?=	../../misc/kuserfeedback

.endif	# KUSERFEEDBACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-kuserfeedback
