# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:19 joerg Exp $

BUILDLINK_TREE+=	libidea

.if !defined(LIBIDEA_BUILDLINK3_MK)
LIBIDEA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libidea+=	libidea>=0.8.2
BUILDLINK_PKGSRCDIR.libidea?=	../../security/libidea
BUILDLINK_DEPMETHOD.libidea?=	build
.endif # LIBIDEA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libidea
