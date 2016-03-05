# $NetBSD: buildlink3.mk,v 1.2 2016/03/05 11:27:47 jperkin Exp $

BUILDLINK_TREE+=	xulrunner38

.if !defined(XULRUNNER38_BUILDLINK3_MK)
XULRUNNER38_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xulrunner38+=	xulrunner38>=38.4.0
BUILDLINK_ABI_DEPENDS.xulrunner38+=	xulrunner38>=38.6.1nb1
BUILDLINK_PKGSRCDIR.xulrunner38?=	../../devel/xulrunner38

BUILDLINK_INCDIRS.xulrunner38+=		lib/xulrunner38/include
BUILDLINK_INCDIRS.xulrunner38+=		include/xulrunner38
BUILDLINK_FILES.xulrunner38+=		lib/xulrunner38/include/*.h

BUILDLINK_LIBDIRS.xulrunner38+=		lib/xulrunner38/lib
BUILDLINK_FILES.xulrunner38+=		lib/xulrunner38/lib/*.so
BUILDLINK_FILES.xulrunner38+=		lib/xulrunner38/pkgconfig/*pc
BUILDLINK_FNAME_TRANSFORM.xulrunner38+=	-e "s|lib/xulrunner38/pkgconfig|lib/pkgconfig|"

pkgbase := xulrunner38
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.xulrunner38:Mgnome)
. include "../../devel/libgnomeui/buildlink3.mk"
. include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif
.include "../../devel/nspr/buildlink3.mk"
.endif # XULRUNNER38_BUILDLINK3_MK

BUILDLINK_TREE+=	-xulrunner38
