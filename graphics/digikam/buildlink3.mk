# $NetBSD: buildlink3.mk,v 1.1 2004/09/23 08:58:59 seb Exp $

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

BUILDLINK_DEPMETHOD.kdesdk=	build

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/kdesdk3/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
