# $NetBSD: buildlink3.mk,v 1.3 2025/10/23 20:36:10 wiz Exp $

BUILDLINK_TREE+=	libmongo-client

.if !defined(LIBMONGO_CLIENT_BUILDLINK3_MK)
LIBMONGO_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmongo-client+=	libmongo-client>=0.1.8
BUILDLINK_ABI_DEPENDS.libmongo-client?=	libmongo-client>=0.1.8nb3
BUILDLINK_PKGSRCDIR.libmongo-client?=	../../databases/libmongo-client

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBMONGO_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmongo-client
