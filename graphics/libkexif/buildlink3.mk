# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:09:35 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBKEXIF_BUILDLINK3_MK:=	${LIBKEXIF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libkexif
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibkexif}
BUILDLINK_PACKAGES+=	libkexif

.if !empty(LIBKEXIF_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libkexif+=	libkexif>=0.2.1
BUILDLINK_RECOMMENDED.libkexif?=	libkexif>=0.2.2nb2
BUILDLINK_PKGSRCDIR.libkexif?=	../../graphics/libkexif
.endif	# LIBKEXIF_BUILDLINK3_MK

.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
