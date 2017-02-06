# $NetBSD: buildlink3.mk,v 1.3 2017/02/06 13:54:41 wiz Exp $

BUILDLINK_TREE+=	libindicator

.if !defined(LIBINDICATOR_BUILDLINK3_MK)
LIBINDICATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libindicator+=	libindicator>=12.10.1
BUILDLINK_ABI_DEPENDS.libindicator?=	libindicator>=12.10.1nb2
BUILDLINK_PKGSRCDIR.libindicator?=	../../devel/libindicator

.include "../../x11/gtk2/buildlink3.mk"
.endif	# LIBINDICATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libindicator
