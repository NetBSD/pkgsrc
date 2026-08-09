# $NetBSD: buildlink3.mk,v 1.1 2026/08/09 17:59:07 wiz Exp $

BUILDLINK_TREE+=	libspelling

.if !defined(LIBSPELLING_BUILDLINK3_MK)
LIBSPELLING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspelling+=	libspelling>=0.4.10
BUILDLINK_PKGSRCDIR.libspelling?=	../../textproc/libspelling

.include "../../x11/gtk4/buildlink3.mk"
.include "../../x11/gtksourceview5/buildlink3.mk"
.endif	# LIBSPELLING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspelling
