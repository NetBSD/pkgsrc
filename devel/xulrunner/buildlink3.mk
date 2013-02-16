# $NetBSD: buildlink3.mk,v 1.33 2013/02/16 11:19:09 wiz Exp $

BUILDLINK_TREE+=	xulrunner

.if !defined(XULRUNNER_BUILDLINK3_MK)
XULRUNNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xulrunner+=	xulrunner>=11.0
BUILDLINK_ABI_DEPENDS.xulrunner+=	xulrunner>=18.0.2nb1
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
.include "../../devel/nspr/buildlink3.mk"
.endif # XULRUNNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xulrunner
