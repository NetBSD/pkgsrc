# $NetBSD: buildlink3.mk,v 1.11 2025/02/12 06:45:22 ryoon Exp $

BUILDLINK_TREE+=	libgravatar

.if !defined(LIBGRAVATAR_BUILDLINK3_MK)
LIBGRAVATAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgravatar+=	libgravatar>=20.04.1
BUILDLINK_ABI_DEPENDS.libgravatar?=	libgravatar>=23.08.4nb7
BUILDLINK_PKGSRCDIR.libgravatar?=	../../misc/libgravatar

.include "../../misc/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBGRAVATAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgravatar
