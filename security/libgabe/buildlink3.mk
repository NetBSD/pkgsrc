# $NetBSD: buildlink3.mk,v 1.1 2020/04/28 13:46:35 nikita Exp $

BUILDLINK_TREE+=	libgabe

.if !defined(LIBGABE_BUILDLINK3_MK)
LIBGABE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgabe+=	libgabe>=1.0
BUILDLINK_PKGSRCDIR.libgabe?=	../../security/libgabe

pkgbase:= libgabe
.include "../../mk/pkg-build-options.mk"

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libpbc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # LIBGABE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgabe
