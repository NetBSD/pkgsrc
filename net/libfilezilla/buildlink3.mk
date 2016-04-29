# $NetBSD: buildlink3.mk,v 1.1 2016/04/29 11:54:06 wiz Exp $

BUILDLINK_TREE+=	libfilezilla

.if !defined(LIBFILEZILLA_BUILDLINK3_MK)
LIBFILEZILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfilezilla+=	libfilezilla>=0.5.0
BUILDLINK_PKGSRCDIR.libfilezilla?=	../../net/libfilezilla
.endif	# LIBFILEZILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfilezilla
