# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:03:57 rillig Exp $

BUILDLINK_TREE+=	libsyncml

.if !defined(LIBSYNCML_BUILDLINK3_MK)
LIBSYNCML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsyncml+=	libsyncml>=0.4.5
BUILDLINK_PKGSRCDIR.libsyncml?=		../../comms/libsyncml

.include "../../textproc/wbxml2/buildlink3.mk"
.endif # LIBSYNCML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsyncml
