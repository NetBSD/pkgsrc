# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/15 08:58:27 ryoon Exp $

BUILDLINK_TREE+=	xulrunner10

.if !defined(XULRUNNER10_BUILDLINK3_MK)
XULRUNNER10_BUILDLINK3_MK:=

pre-configure: xulrunner10-preconfigure
.PHONY: xulrunner10-preconfigure
xulrunner10-preconfigure:
	cp ${PREFIX}/lib/xulrunner10/pkgconfig/* ${BUILDLINK_DIR}/lib/pkgconfig

BUILDLINK_API_DEPENDS.xulrunner10+=	xulrunner10>=10.0.2
BUILDLINK_ABI_DEPENDS.xulrunner10?=	xulrunner10>=10.0.2
BUILDLINK_PKGSRCDIR.xulrunner10?=	../../devel/xulrunner10

BUILDLINK_INCDIRS.xulrunner10+=		lib/xulrunner10-sdk/include
BUILDLINK_INCDIRS.xulrunner10+=		include/xulrunner10
BUILDLINK_FILES.xulrunner10+=		lib/xulrunner10-sdk/include/*.h

BUILDLINK_LIBDIRS.xulrunner10+=		lib/xulrunner10-sdk/lib
BUILDLINK_FILES.xulrunner10+=		lib/xulrunner10-sdk/lib/*.so

pkgbase := xulrunner10
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.xulrunner10:Mgnome)
. include "../../devel/libgnomeui/buildlink3.mk"
. include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif
.endif # XULRUNNER10_BUILDLINK3_MK

BUILDLINK_TREE+=	-xulrunner10
