# $NetBSD: buildlink3.mk,v 1.40 2023/01/03 17:36:32 wiz Exp $

BUILDLINK_TREE+=	libgksu

.if !defined(LIBGKSU_BUILDLINK3_MK)
LIBGKSU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgksu+=	libgksu>=2.0.7
BUILDLINK_ABI_DEPENDS.libgksu+=	libgksu>=2.0.12nb18
BUILDLINK_PKGSRCDIR.libgksu?=	../../sysutils/libgksu

.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif # LIBGKSU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgksu
