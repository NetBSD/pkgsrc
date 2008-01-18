# $NetBSD: buildlink3.mk,v 1.18 2008/01/18 05:06:38 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DIGIKAM_BUILDLINK3_MK:=	${DIGIKAM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	digikam
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndigikam}
BUILDLINK_PACKAGES+=	digikam
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}digikam

.if !empty(DIGIKAM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.digikam+=	digikam>=0.8.1
BUILDLINK_ABI_DEPENDS.digikam?=	digikam>=0.9.3nb2
BUILDLINK_PKGSRCDIR.digikam?=	../../graphics/digikam
.endif	# DIGIKAM_BUILDLINK3_MK

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
