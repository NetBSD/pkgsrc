# $NetBSD: buildlink3.mk,v 1.1 2014/11/13 11:05:43 markd Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.baloo-widgets?=	build

BUILDLINK_TREE+=	baloo-widgets

.if !defined(BALOO_WIDGETS_BUILDLINK3_MK)
BALOO_WIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.baloo-widgets+=	baloo-widgets>=4.14.3
BUILDLINK_PKGSRCDIR.baloo-widgets?=	../../sysutils/baloo-widgets

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../sysutils/baloo/buildlink3.mk"
#.include "../../sysutils/kfilemetadata/buildlink3.mk"
#.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# BALOO_WIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-baloo-widgets
