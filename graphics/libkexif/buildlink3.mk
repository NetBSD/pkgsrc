# $NetBSD: buildlink3.mk,v 1.6 2006/04/17 13:46:06 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBKEXIF_BUILDLINK3_MK:=	${LIBKEXIF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libkexif
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibkexif}
BUILDLINK_PACKAGES+=	libkexif

.if !empty(LIBKEXIF_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libkexif+=	libkexif>=0.2.1
BUILDLINK_ABI_DEPENDS.libkexif?=	libkexif>=0.2.2nb3
BUILDLINK_PKGSRCDIR.libkexif?=	../../graphics/libkexif
.endif	# LIBKEXIF_BUILDLINK3_MK

.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
