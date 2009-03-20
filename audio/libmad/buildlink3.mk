# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:23:55 joerg Exp $

BUILDLINK_TREE+=	libmad

.if !defined(LIBMAD_BUILDLINK3_MK)
LIBMAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmad+=	libmad>=0.15.0b
BUILDLINK_ABI_DEPENDS.libmad+=	libmad>=0.15.1bnb1
BUILDLINK_PKGSRCDIR.libmad?=	../../audio/libmad
.endif # LIBMAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmad
