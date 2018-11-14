# $NetBSD: buildlink3.mk,v 1.39 2018/11/14 22:21:21 kleink Exp $

BUILDLINK_TREE+=	xulrunner192

.if !defined(XULRUNNER192_BUILDLINK3_MK)
XULRUNNER192_BUILDLINK3_MK:=

pre-configure: xulrunner192-preconfigure
.PHONY: xulrunner192-preconfigure
xulrunner192-preconfigure:
	cp ${PREFIX}/lib/xulrunner192/pkgconfig/* ${BUILDLINK_DIR}/lib/pkgconfig

BUILDLINK_API_DEPENDS.xulrunner192+=	xulrunner192>=1.9.2.17nb2<2.0
BUILDLINK_ABI_DEPENDS.xulrunner192+=	xulrunner192>=1.9.2.28nb49
BUILDLINK_PKGSRCDIR.xulrunner192?=	../../devel/xulrunner192

pkgbase := xulrunner192
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.xulrunner192:Mgnome)
.  include "../../devel/libgnomeui/buildlink3.mk"
.  include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif
.endif # XULRUNNER192_BUILDLINK3_MK

BUILDLINK_TREE+=	-xulrunner192
