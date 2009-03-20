# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:20 joerg Exp $

BUILDLINK_TREE+=	libmcs

.if !defined(LIBMCS_BUILDLINK3_MK)
LIBMCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmcs+=	libmcs>=0.7.1
BUILDLINK_PKGSRCDIR.libmcs?=	../../devel/libmcs

.include "../../devel/libmowgli/buildlink3.mk"
.endif # LIBMCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmcs
