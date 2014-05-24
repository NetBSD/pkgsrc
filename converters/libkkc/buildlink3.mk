# $NetBSD: buildlink3.mk,v 1.1 2014/05/24 13:10:04 obache Exp $
#

BUILDLINK_TREE+=	libkkc

.if !defined(LIBKKC_BUILDLINK3_MK)
LIBKKC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkkc+=	libkkc>=0.3.3
BUILDLINK_PKGSRCDIR.libkkc?=	../../converters/libkkc

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/marisa/buildlink3.mk"
.endif	# LIBKKC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkkc
