# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:03 joerg Exp $

BUILDLINK_TREE+=	synce-libsynce

.if !defined(SYNCE_LIBSYNCE_BUILDLINK3_MK)
SYNCE_LIBSYNCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.synce-libsynce+=	synce-libsynce>=0.9.1
BUILDLINK_PKGSRCDIR.synce-libsynce?=	../../comms/synce-libsynce

.include "../../converters/libiconv/buildlink3.mk"
.endif # SYNCE_LIBSYNCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-synce-libsynce
