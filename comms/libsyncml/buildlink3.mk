# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:02 joerg Exp $

BUILDLINK_TREE+=	libsyncml

.if !defined(LIBSYNCML_BUILDLINK3_MK)
LIBSYNCML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsyncml+=	libsyncml>=0.4.5
BUILDLINK_PKGSRCDIR.libsyncml?=	../../comms/libsyncml
.endif # LIBSYNCML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsyncml
