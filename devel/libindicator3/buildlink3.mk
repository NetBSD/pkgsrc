# $NetBSD: buildlink3.mk,v 1.1 2016/05/20 21:33:13 youri Exp $

BUILDLINK_TREE+=	libindicator3

.if !defined(LIBINDICATOR3_BUILDLINK3_MK)
LIBINDICATOR3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libindicator3+=	libindicator3>=12.10.1
BUILDLINK_PKGSRCDIR.libindicator3?=	../../devel/libindicator3

.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBINDICATOR3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libindicator3
