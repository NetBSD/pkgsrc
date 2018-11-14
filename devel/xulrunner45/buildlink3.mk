# $NetBSD: buildlink3.mk,v 1.11 2018/11/14 22:21:21 kleink Exp $

BUILDLINK_TREE+=	xulrunner45

.if !defined(XULRUNNER45_BUILDLINK3_MK)
XULRUNNER45_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xulrunner45+=	xulrunner45>=45.1.0
BUILDLINK_ABI_DEPENDS.xulrunner45+=	xulrunner45>=45.9.0nb6
BUILDLINK_PKGSRCDIR.xulrunner45?=	../../devel/xulrunner45

BUILDLINK_INCDIRS.xulrunner45+=		lib/xulrunner45/include
BUILDLINK_INCDIRS.xulrunner45+=		include/xulrunner45
BUILDLINK_FILES.xulrunner45+=		lib/xulrunner45/include/*.h

BUILDLINK_LIBDIRS.xulrunner45+=		lib/xulrunner45/lib
BUILDLINK_FILES.xulrunner45+=		lib/xulrunner45/lib/*.so
BUILDLINK_FILES.xulrunner45+=		lib/xulrunner45/pkgconfig/*pc
BUILDLINK_FNAME_TRANSFORM.xulrunner45+=	-e "s|lib/xulrunner45/pkgconfig|lib/pkgconfig|"

pkgbase := xulrunner45
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.xulrunner45:Mgnome)
.  include "../../devel/libgnomeui/buildlink3.mk"
.  include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif
.include "../../devel/nspr/buildlink3.mk"
.endif # XULRUNNER45_BUILDLINK3_MK

BUILDLINK_TREE+=	-xulrunner45
