# $NetBSD: buildlink3.mk,v 1.3 2026/11/11 11:55:04 wiz Exp $

BUILDLINK_TREE+=	libfilezilla

.if !defined(LIBFILEZILLA_BUILDLINK3_MK)
LIBFILEZILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfilezilla+=	libfilezilla>=0.5.0
BUILDLINK_ABI_DEPENDS.libfilezilla?=	libfilezilla>=0.57.0nb1
BUILDLINK_PKGSRCDIR.libfilezilla?=	../../net/libfilezilla
.include "../../security/nettle/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif	# LIBFILEZILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfilezilla
