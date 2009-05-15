# $NetBSD: buildlink3.mk,v 1.3 2009/05/15 08:55:35 obache Exp $

BUILDLINK_TREE+=	libthai

.if !defined(LIBTHAI_BUILDLINK3_MK)
LIBTHAI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libthai+=	libthai>=0.1.10
BUILDLINK_PKGSRCDIR.libthai?=	../../devel/libthai

.include "../../devel/libdatrie/buildlink3.mk"
.endif # LIBTHAI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libthai
