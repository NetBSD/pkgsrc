# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:43 joerg Exp $

BUILDLINK_TREE+=	libungif

.if !defined(LIBUNGIF_BUILDLINK3_MK)
LIBUNGIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libungif+=	libungif>=4.1.0
BUILDLINK_ABI_DEPENDS.libungif+=	libungif>=4.1.3nb1
BUILDLINK_PKGSRCDIR.libungif?=	../../graphics/libungif
.endif # LIBUNGIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libungif
