# $NetBSD: buildlink3.mk,v 1.7 2010/03/16 15:57:02 tnn Exp $

BUILDLINK_TREE+=	xulrunner

.if !defined(XULRUNNER_BUILDLINK3_MK)
XULRUNNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xulrunner+=	xulrunner>=1.9.2.2
BUILDLINK_ABI_DEPENDS.xulrunner?=	xulrunner>=1.9.2.2
BUILDLINK_PKGSRCDIR.xulrunner?=		../../devel/xulrunner

pkgbase := xulrunner
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.xulrunner:Mgnome)
. include "../../devel/libgnomeui/buildlink3.mk"
. include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif
.endif # XULRUNNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xulrunner
