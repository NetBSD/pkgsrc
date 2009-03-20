# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:20 joerg Exp $

BUILDLINK_TREE+=	libssh

.if !defined(LIBSSH_BUILDLINK3_MK)
LIBSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh+=	libssh>=0.11
BUILDLINK_PKGSRCDIR.libssh?=	../../security/libssh
.endif # LIBSSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libssh
