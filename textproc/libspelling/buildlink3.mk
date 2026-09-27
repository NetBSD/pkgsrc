# $NetBSD: buildlink3.mk,v 1.3 2026/09/27 11:38:52 tnn Exp $

BUILDLINK_TREE+=	libspelling

.if !defined(LIBSPELLING_BUILDLINK3_MK)
LIBSPELLING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspelling+=	libspelling>=0.4.10
BUILDLINK_ABI_DEPENDS.libspelling?=	libspelling>=0.4.10nb2
BUILDLINK_PKGSRCDIR.libspelling?=	../../textproc/libspelling

.include "../../x11/gtk4/buildlink3.mk"
.include "../../x11/gtksourceview5/buildlink3.mk"
.endif	# LIBSPELLING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspelling
