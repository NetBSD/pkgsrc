# $NetBSD: buildlink3.mk,v 1.5 2014/11/03 18:45:43 prlw1 Exp $
#

BUILDLINK_TREE+=	libskk

.if !defined(LIBSKK_BUILDLINK3_MK)
LIBSKK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libskk+=	libskk>=1.0.2
BUILDLINK_PKGSRCDIR.libskk?=	../../inputmethod/libskk

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.endif	# LIBSKK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libskk
