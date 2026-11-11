# $NetBSD: buildlink3.mk,v 1.6 2026/11/11 11:55:56 wiz Exp $

BUILDLINK_TREE+=	libspelling

.if !defined(LIBSPELLING_BUILDLINK3_MK)
LIBSPELLING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspelling+=	libspelling>=0.4.10
BUILDLINK_ABI_DEPENDS.libspelling+=	libspelling>=0.4.11nb1
BUILDLINK_PKGSRCDIR.libspelling?=	../../textproc/libspelling

.include "../../x11/gtk4/buildlink3.mk"
.include "../../x11/gtksourceview5/buildlink3.mk"
.endif	# LIBSPELLING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspelling
