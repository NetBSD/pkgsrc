# $NetBSD: buildlink3.mk,v 1.1 2020/06/11 13:45:36 ryoon Exp $

BUILDLINK_TREE+=	libsignal-protocol-c

.if !defined(LIBSIGNAL_PROTOCOL_C_BUILDLINK3_MK)
LIBSIGNAL_PROTOCOL_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsignal-protocol-c+=	libsignal-protocol-c>=2.3.3
BUILDLINK_PKGSRCDIR.libsignal-protocol-c?=	../../chat/libsignal-protocol-c
.endif	# LIBSIGNAL_PROTOCOL_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsignal-protocol-c
