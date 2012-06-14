# $NetBSD: buildlink3.mk,v 1.3 2012/06/14 07:43:21 sbd Exp $

BUILDLINK_TREE+=	libxmlpp1

.if !defined(LIBXMLPP1_BUILDLINK3_MK)
LIBXMLPP1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxmlpp1+=	libxml++1>=1.0.5
BUILDLINK_ABI_DEPENDS.libxmlpp1?=		libxml++1>=1.0.5nb1
BUILDLINK_PKGSRCDIR.libxmlpp1?=		../../textproc/libxml++1

.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBXMLPP1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxmlpp1
