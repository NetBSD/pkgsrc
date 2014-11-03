# $NetBSD: buildlink3.mk,v 1.3 2014/11/03 18:45:42 prlw1 Exp $
#

BUILDLINK_TREE+=	libkkc

.if !defined(LIBKKC_BUILDLINK3_MK)
LIBKKC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkkc+=	libkkc>=0.3.4
BUILDLINK_PKGSRCDIR.libkkc?=	../../converters/libkkc

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/marisa/buildlink3.mk"
.endif	# LIBKKC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkkc
