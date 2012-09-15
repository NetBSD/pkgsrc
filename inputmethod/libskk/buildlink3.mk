# $NetBSD: buildlink3.mk,v 1.2 2012/09/15 10:05:14 obache Exp $
#

BUILDLINK_TREE+=	libskk

.if !defined(LIBSKK_BUILDLINK3_MK)
LIBSKK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libskk+=	libskk>=0.0.12
BUILDLINK_ABI_DEPENDS.libskk?=	libskk>=0.0.13nb1
BUILDLINK_PKGSRCDIR.libskk?=	../../inputmethod/libskk

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.endif	# LIBSKK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libskk
