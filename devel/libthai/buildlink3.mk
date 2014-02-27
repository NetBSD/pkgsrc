# $NetBSD: buildlink3.mk,v 1.4 2014/02/27 12:45:24 obache Exp $

BUILDLINK_TREE+=	libthai

.if !defined(LIBTHAI_BUILDLINK3_MK)
LIBTHAI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libthai+=	libthai>=0.1.10
BUILDLINK_ABI_DEPENDS.libthai+=	libthai>=0.1.20
BUILDLINK_PKGSRCDIR.libthai?=	../../devel/libthai

.include "../../devel/libdatrie/buildlink3.mk"
.endif # LIBTHAI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libthai
