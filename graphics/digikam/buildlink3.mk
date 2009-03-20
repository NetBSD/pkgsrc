# $NetBSD: buildlink3.mk,v 1.20 2009/03/20 19:24:37 joerg Exp $

BUILDLINK_TREE+=	digikam

.if !defined(DIGIKAM_BUILDLINK3_MK)
DIGIKAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.digikam+=	digikam>=0.8.1
BUILDLINK_ABI_DEPENDS.digikam?=	digikam>=0.9.5beta1nb1
BUILDLINK_PKGSRCDIR.digikam?=	../../graphics/digikam

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.endif # DIGIKAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-digikam
