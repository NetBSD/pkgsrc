# $NetBSD: buildlink3.mk,v 1.21 2012/03/06 12:34:08 ryoon Exp $

BUILDLINK_TREE+=	xulrunner

.if !defined(XULRUNNER_BUILDLINK3_MK)
XULRUNNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xulrunner+=	xulrunner>=6.0
BUILDLINK_ABI_DEPENDS.xulrunner?=		xulrunner>=8.0nb2
BUILDLINK_PKGSRCDIR.xulrunner?=		../../devel/xulrunner

BUILDLINK_INCDIRS.xulrunner+=		lib/xulrunner-sdk/include
BUILDLINK_INCDIRS.xulrunner+=		include/xulrunner
BUILDLINK_FILES.xulrunner+=		lib/xulrunner-sdk/include/*.h

BUILDLINK_LIBDIRS.xulrunner+=		lib/xulrunner-sdk/lib
BUILDLINK_FILES.xulrunner+=		lib/xulrunner-sdk/lib/*.so

pkgbase := xulrunner
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.xulrunner:Mgnome)
. include "../../devel/libgnomeui/buildlink3.mk"
. include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif
.endif # XULRUNNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xulrunner
