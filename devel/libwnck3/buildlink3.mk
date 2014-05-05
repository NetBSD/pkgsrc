# $NetBSD: buildlink3.mk,v 1.8 2014/05/05 00:47:45 ryoon Exp $

BUILDLINK_TREE+=	libwnck3

.if !defined(LIBWNCK3_BUILDLINK3_MK)
LIBWNCK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwnck3+=	libwnck>=3.2.1
BUILDLINK_ABI_DEPENDS.libwnck3?=	libwnck3>=3.4.7nb2
BUILDLINK_PKGSRCDIR.libwnck3?=	../../devel/libwnck3

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif # LIBWNCK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwnck3
