# $NetBSD: buildlink3.mk,v 1.4 2004/10/03 00:14:55 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBEXIF_BUILDLINK3_MK:=	${LIBEXIF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libexif
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibexif}
BUILDLINK_PACKAGES+=	libexif

.if !empty(LIBEXIF_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libexif+=	libexif>=0.5.12
BUILDLINK_RECOMMENDED.libexif+=	libexif>=0.5.12nb2
BUILDLINK_PKGSRCDIR.libexif?=	../../graphics/libexif
.endif	# LIBEXIF_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
