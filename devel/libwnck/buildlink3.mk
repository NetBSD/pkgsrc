# $NetBSD: buildlink3.mk,v 1.47 2018/11/12 03:51:13 ryoon Exp $

BUILDLINK_TREE+=	libwnck

.if !defined(LIBWNCK_BUILDLINK3_MK)
LIBWNCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwnck+=	libwnck>=2.20.0
BUILDLINK_ABI_DEPENDS.libwnck+=	libwnck>=2.30.6nb24
BUILDLINK_PKGSRCDIR.libwnck?=	../../devel/libwnck

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif # LIBWNCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwnck
