# $NetBSD: buildlink3.mk,v 1.3 2012/09/07 19:17:11 adam Exp $

BUILDLINK_TREE+=	libkvkontakte

.if !defined(LIBKVKONTAKTE_BUILDLINK3_MK)
LIBKVKONTAKTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkvkontakte+=	libkvkontakte>=2.5.0
BUILDLINK_ABI_DEPENDS.libkvkontakte?=	libkvkontakte>=2.5.0nb2
BUILDLINK_PKGSRCDIR.libkvkontakte?=	../../misc/libkvkontakte

.include "../../devel/qjson/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKVKONTAKTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkvkontakte
