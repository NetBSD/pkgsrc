# $NetBSD: buildlink3.mk,v 1.12 2020/11/24 11:13:25 nia Exp $

BUILDLINK_TREE+=	libdockapp

.if !defined(LIBDOCKAPP_BUILDLINK3_MK)
LIBDOCKAPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdockapp+=	libdockapp>=0.4.0
BUILDLINK_ABI_DEPENDS.libdockapp+=	libdockapp>=0.4.0nb2
BUILDLINK_PKGSRCDIR.libdockapp?=	../../devel/libdockapp
BUILDLINK_INCDIRS.libdockapp+=		include/libdockapp

.include "../../x11/libXpm/buildlink3.mk"
.endif # LIBDOCKAPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdockapp
