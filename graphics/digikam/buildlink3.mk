# $NetBSD: buildlink3.mk,v 1.5 2005/01/09 11:14:09 seb Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DIGIKAM_BUILDLINK3_MK:=	${DIGIKAM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	digikam
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndigikam}
BUILDLINK_PACKAGES+=	digikam

.if !empty(DIGIKAM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.digikam+=	digikam>=0.7.1
BUILDLINK_PKGSRCDIR.digikam?=	../../graphics/digikam
.endif	# DIGIKAM_BUILDLINK3_MK

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/libkexif/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
