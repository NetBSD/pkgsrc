# $NetBSD: buildlink3.mk,v 1.1 2016/05/20 21:32:24 youri Exp $

BUILDLINK_TREE+=	libindicator

.if !defined(LIBINDICATOR_BUILDLINK3_MK)
LIBINDICATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libindicator+=	libindicator>=12.10.1
BUILDLINK_PKGSRCDIR.libindicator?=	../../devel/libindicator

.include "../../x11/gtk2/buildlink3.mk"
.endif	# LIBINDICATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libindicator
