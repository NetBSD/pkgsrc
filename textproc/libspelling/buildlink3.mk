# $NetBSD: buildlink3.mk,v 1.5 2026/11/10 08:33:27 adam Exp $

BUILDLINK_TREE+=	libspelling

.if !defined(LIBSPELLING_BUILDLINK3_MK)
LIBSPELLING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspelling+=	libspelling>=0.4.10
BUILDLINK_ABI_DEPENDS.libspelling+=	libspelling>=0.4.10nb3
BUILDLINK_PKGSRCDIR.libspelling?=	../../textproc/libspelling

.include "../../x11/gtk4/buildlink3.mk"
.include "../../x11/gtksourceview5/buildlink3.mk"
.endif	# LIBSPELLING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspelling
