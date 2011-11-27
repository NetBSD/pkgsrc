# $NetBSD: buildlink3.mk,v 1.9 2011/11/27 03:49:03 sbd Exp $

BUILDLINK_TREE+=	libssh

.if !defined(LIBSSH_BUILDLINK3_MK)
LIBSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh+=	libssh>=0.11
BUILDLINK_ABI_DEPENDS.libssh?=	libssh>=0.11nb3
BUILDLINK_PKGSRCDIR.libssh?=	../../security/libssh

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBSSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libssh
