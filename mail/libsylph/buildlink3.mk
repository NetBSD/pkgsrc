# $NetBSD: buildlink3.mk,v 1.12 2016/03/05 11:27:50 jperkin Exp $

BUILDLINK_TREE+=	libsylph

.if !defined(LIBSYLPH_BUILDLINK3_MK)
LIBSYLPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsylph+=	libsylph>=0.3.0
BUILDLINK_ABI_DEPENDS.libsylph+=	libsylph>=1.1.0nb4
BUILDLINK_PKGSRCDIR.libsylph?=	../../mail/libsylph

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LIBSYLPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsylph
