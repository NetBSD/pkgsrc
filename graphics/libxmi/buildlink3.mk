# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/01 14:33:39 adam Exp $

BUILDLINK_TREE+=	libxmi

.if !defined(LIBXMI_BUILDLINK3_MK)
LIBXMI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxmi+=	libxmi>=1.2
BUILDLINK_PKGSRCDIR.libxmi?=	../../graphics/libxmi
.endif	# LIBXMI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxmi
