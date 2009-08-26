# $NetBSD: buildlink3.mk,v 1.21 2009/08/26 19:56:45 sno Exp $

BUILDLINK_TREE+=	digikam

.if !defined(DIGIKAM_BUILDLINK3_MK)
DIGIKAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.digikam+=	digikam>=0.8.1
BUILDLINK_ABI_DEPENDS.digikam?=	digikam>=0.9.6nb1
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
