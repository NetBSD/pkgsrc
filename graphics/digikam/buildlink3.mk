# $NetBSD: buildlink3.mk,v 1.2 2004/09/25 23:57:34 seb Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DIGIKAM_BUILDLINK3_MK:=	${DIGIKAM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	digikam
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndigikam}
BUILDLINK_PACKAGES+=	digikam

.if !empty(DIGIKAM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.digikam+=	digikam>=0.6.2
BUILDLINK_PKGSRCDIR.digikam?=	../../graphics/digikam
.endif	# DIGIKAM_BUILDLINK3_MK

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
