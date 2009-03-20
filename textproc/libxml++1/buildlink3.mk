# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:31 joerg Exp $

BUILDLINK_TREE+=	libxmlpp1

.if !defined(LIBXMLPP1_BUILDLINK3_MK)
LIBXMLPP1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxmlpp1+=	libxml++1>=1.0.5
BUILDLINK_PKGSRCDIR.libxmlpp1?=		../../textproc/libxml++1

.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBXMLPP1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxmlpp1
