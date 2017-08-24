# $NetBSD: buildlink3.mk,v 1.27 2017/08/24 20:03:00 adam Exp $

BUILDLINK_TREE+=	libkvkontakte

.if !defined(LIBKVKONTAKTE_BUILDLINK3_MK)
LIBKVKONTAKTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkvkontakte+=	libkvkontakte>=2.5.0
BUILDLINK_ABI_DEPENDS.libkvkontakte?=	libkvkontakte>=4.13.0nb5
BUILDLINK_PKGSRCDIR.libkvkontakte?=	../../misc/libkvkontakte

.include "../../devel/qjson/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKVKONTAKTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkvkontakte
