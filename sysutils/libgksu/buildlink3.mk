# $NetBSD: buildlink3.mk,v 1.37 2020/03/08 16:48:11 wiz Exp $

BUILDLINK_TREE+=	libgksu

.if !defined(LIBGKSU_BUILDLINK3_MK)
LIBGKSU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgksu+=	libgksu>=2.0.7
BUILDLINK_ABI_DEPENDS.libgksu+=	libgksu>=2.0.12nb14
BUILDLINK_PKGSRCDIR.libgksu?=	../../sysutils/libgksu

.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif # LIBGKSU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgksu
