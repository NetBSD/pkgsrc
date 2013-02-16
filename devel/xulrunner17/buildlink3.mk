# $NetBSD: buildlink3.mk,v 1.5 2013/02/16 11:19:09 wiz Exp $

BUILDLINK_TREE+=	xulrunner17

.if !defined(XULRUNNER17_BUILDLINK3_MK)
XULRUNNER17_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xulrunner17+=	xulrunner17>=17.0.2
BUILDLINK_ABI_DEPENDS.xulrunner17+=	xulrunner17>=17.0.2nb3
BUILDLINK_PKGSRCDIR.xulrunner17?=		../../devel/xulrunner17

BUILDLINK_INCDIRS.xulrunner17+=		lib/xulrunner17-sdk/include
BUILDLINK_INCDIRS.xulrunner17+=		include/xulrunner17
BUILDLINK_FILES.xulrunner17+=		lib/xulrunner17-sdk/include/*.h

BUILDLINK_LIBDIRS.xulrunner17+=		lib/xulrunner17-sdk/lib
BUILDLINK_FILES.xulrunner17+=		lib/xulrunner17-sdk/lib/*.so

pkgbase := xulrunner17
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.xulrunner17:Mgnome)
. include "../../devel/libgnomeui/buildlink3.mk"
. include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif
.include "../../devel/nspr/buildlink3.mk"
.endif # XULRUNNER17_BUILDLINK3_MK

BUILDLINK_TREE+=	-xulrunner17
