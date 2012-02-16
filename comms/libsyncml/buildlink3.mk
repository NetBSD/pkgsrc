# $NetBSD: buildlink3.mk,v 1.3 2012/02/16 17:22:39 hans Exp $

BUILDLINK_TREE+=	libsyncml

.if !defined(LIBSYNCML_BUILDLINK3_MK)
LIBSYNCML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsyncml+=	libsyncml>=0.4.5
BUILDLINK_PKGSRCDIR.libsyncml?=	../../comms/libsyncml

.include "../../textproc/wbxml2/buildlink3.mk"
.endif # LIBSYNCML_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsyncml
