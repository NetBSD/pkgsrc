# $NetBSD: buildlink3.mk,v 1.36 2020/01/18 21:48:17 jperkin Exp $

BUILDLINK_TREE+=	libkvkontakte

.if !defined(LIBKVKONTAKTE_BUILDLINK3_MK)
LIBKVKONTAKTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkvkontakte+=	libkvkontakte>=5.0.0
BUILDLINK_ABI_DEPENDS.libkvkontakte?=	libkvkontakte>=5.0.0nb1
BUILDLINK_PKGSRCDIR.libkvkontakte?=	../../misc/libkvkontakte

.include "../../www/kdewebkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKVKONTAKTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkvkontakte
