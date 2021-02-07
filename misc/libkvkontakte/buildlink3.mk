# $NetBSD: buildlink3.mk,v 1.46 2021/02/07 06:30:09 ryoon Exp $

BUILDLINK_TREE+=	libkvkontakte

.if !defined(LIBKVKONTAKTE_BUILDLINK3_MK)
LIBKVKONTAKTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkvkontakte+=	libkvkontakte>=5.0.0
BUILDLINK_ABI_DEPENDS.libkvkontakte?=	libkvkontakte>=5.0.0nb11
BUILDLINK_PKGSRCDIR.libkvkontakte?=	../../misc/libkvkontakte

.include "../../www/kdewebkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKVKONTAKTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkvkontakte
