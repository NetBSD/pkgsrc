# $NetBSD: buildlink3.mk,v 1.2 2026/05/15 07:37:51 wiz Exp $

BUILDLINK_TREE+=	libfilezilla

.if !defined(LIBFILEZILLA_BUILDLINK3_MK)
LIBFILEZILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfilezilla+=	libfilezilla>=0.5.0
BUILDLINK_PKGSRCDIR.libfilezilla?=	../../net/libfilezilla
.include "../../security/nettle/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif	# LIBFILEZILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfilezilla
