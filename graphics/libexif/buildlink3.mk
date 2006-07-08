# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 22:39:19 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBEXIF_BUILDLINK3_MK:=	${LIBEXIF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libexif
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibexif}
BUILDLINK_PACKAGES+=	libexif
BUILDLINK_ORDER+=	libexif

.if !empty(LIBEXIF_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libexif+=	libexif>=0.6.11
BUILDLINK_ABI_DEPENDS.libexif+=	libexif>=0.6.13nb1
BUILDLINK_PKGSRCDIR.libexif?=	../../graphics/libexif
.endif	# LIBEXIF_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
