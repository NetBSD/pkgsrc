# $NetBSD: buildlink3.mk,v 1.3 2014/02/12 23:17:51 tron Exp $

BUILDLINK_TREE+=	xulrunner24

.if !defined(XULRUNNER24_BUILDLINK3_MK)
XULRUNNER24_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xulrunner24+=	xulrunner24>=24.0
BUILDLINK_ABI_DEPENDS.xulrunner24+=	xulrunner24>=24.2.0nb2
BUILDLINK_PKGSRCDIR.xulrunner24?=		../../devel/xulrunner24

BUILDLINK_INCDIRS.xulrunner24+=		lib/xulrunner24/include
BUILDLINK_INCDIRS.xulrunner24+=		include/xulrunner24
BUILDLINK_FILES.xulrunner24+=		lib/xulrunner24/include/*.h

BUILDLINK_LIBDIRS.xulrunner24+=		lib/xulrunner24/lib
BUILDLINK_FILES.xulrunner24+=		lib/xulrunner24/lib/*.so
BUILDLINK_FILES.xulrunner24+=		lib/xulrunner24/pkgconfig/*pc
BUILDLINK_FNAME_TRANSFORM.xulrunner24+=	-e "s|lib/xulrunner24/pkgconfig|lib/pkgconfig|"

pkgbase := xulrunner24
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.xulrunner24:Mgnome)
. include "../../devel/libgnomeui/buildlink3.mk"
. include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif
.include "../../devel/nspr/buildlink3.mk"
.endif # XULRUNNER24_BUILDLINK3_MK

BUILDLINK_TREE+=	-xulrunner24
