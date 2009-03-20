# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:24 joerg Exp $

BUILDLINK_TREE+=	libgamin

.if !defined(LIBGAMIN_BUILDLINK3_MK)
LIBGAMIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgamin+=	libgamin>=0.1.10
BUILDLINK_PKGSRCDIR.libgamin?=	../../sysutils/libgamin
.endif # LIBGAMIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgamin
