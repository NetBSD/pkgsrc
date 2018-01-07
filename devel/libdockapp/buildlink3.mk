# $NetBSD: buildlink3.mk,v 1.11 2018/01/07 13:04:05 rillig Exp $

BUILDLINK_TREE+=	libdockapp

.if !defined(LIBDOCKAPP_BUILDLINK3_MK)
LIBDOCKAPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdockapp+=	libdockapp>=0.4.0
BUILDLINK_ABI_DEPENDS.libdockapp+=	libdockapp>=0.4.0nb2
BUILDLINK_PKGSRCDIR.libdockapp?=	../../devel/libdockapp

.include "../../x11/libXpm/buildlink3.mk"
.endif # LIBDOCKAPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdockapp
