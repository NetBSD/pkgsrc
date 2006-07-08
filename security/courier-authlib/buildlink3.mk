# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 22:39:36 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
COURIER_AUTHLIB_BUILDLINK3_MK:=	${COURIER_AUTHLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	courier-authlib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncourier-authlib}
BUILDLINK_PACKAGES+=	courier-authlib
BUILDLINK_ORDER+=	courier-authlib

.if !empty(COURIER_AUTHLIB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.courier-authlib+=	courier-authlib>=0.53
BUILDLINK_ABI_DEPENDS.courier-authlib?=	courier-authlib>=0.58nb2
BUILDLINK_PKGSRCDIR.courier-authlib?=	../../security/courier-authlib
.endif	# COURIER_AUTHLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
