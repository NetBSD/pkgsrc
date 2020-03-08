# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:47:29 wiz Exp $

BUILDLINK_TREE+=	libmongo-client

.if !defined(LIBMONGO_CLIENT_BUILDLINK3_MK)
LIBMONGO_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmongo-client+=	libmongo-client>=0.1.8
BUILDLINK_ABI_DEPENDS.libmongo-client?=	libmongo-client>=0.1.8nb1
BUILDLINK_PKGSRCDIR.libmongo-client?=	../../databases/libmongo-client

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBMONGO_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmongo-client
