# $NetBSD: buildlink3.mk,v 1.16 2017/12/29 23:06:14 gdt Exp $

BUILDLINK_TREE+=	glibmm

.if !defined(GLIBMM_BUILDLINK3_MK)
GLIBMM_BUILDLINK3_MK:=

# It is necessary to use the same compiler to link against libmm as it
# was built with.  This is hacky, but enables at least
# gnome-system-monitor to build.
GCC_REQD+=		4.9

BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.24.2
BUILDLINK_ABI_DEPENDS.glibmm+=	glibmm>=2.32.1nb1
BUILDLINK_PKGSRCDIR.glibmm?=	../../devel/glibmm

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.endif # GLIBMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-glibmm
