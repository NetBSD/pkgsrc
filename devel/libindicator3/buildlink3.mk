# $NetBSD: buildlink3.mk,v 1.6 2018/03/12 11:15:30 wiz Exp $

BUILDLINK_TREE+=	libindicator3

.if !defined(LIBINDICATOR3_BUILDLINK3_MK)
LIBINDICATOR3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libindicator3+=	libindicator3>=12.10.1
BUILDLINK_ABI_DEPENDS.libindicator3?=	libindicator3>=12.10.1nb5
BUILDLINK_PKGSRCDIR.libindicator3?=	../../devel/libindicator3

.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBINDICATOR3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libindicator3
