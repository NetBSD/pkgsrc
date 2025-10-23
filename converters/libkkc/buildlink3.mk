# $NetBSD: buildlink3.mk,v 1.6 2025/10/23 20:36:08 wiz Exp $
#

BUILDLINK_TREE+=	libkkc

.if !defined(LIBKKC_BUILDLINK3_MK)
LIBKKC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkkc+=	libkkc>=0.3.4
BUILDLINK_ABI_DEPENDS.libkkc?=	libkkc>=0.3.5nb6
BUILDLINK_PKGSRCDIR.libkkc?=	../../converters/libkkc

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/marisa/buildlink3.mk"
.endif	# LIBKKC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkkc
