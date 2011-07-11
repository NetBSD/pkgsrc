# $NetBSD: buildlink3.mk,v 1.14 2011/07/11 12:46:14 tnn Exp $

BUILDLINK_TREE+=	xulrunner

.if !defined(XULRUNNER_BUILDLINK3_MK)
XULRUNNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xulrunner+=	xulrunner>=5.0
BUILDLINK_PKGSRCDIR.xulrunner?=		../../devel/xulrunner

pkgbase := xulrunner
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.xulrunner:Mgnome)
. include "../../devel/libgnomeui/buildlink3.mk"
. include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif
.endif # XULRUNNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xulrunner
