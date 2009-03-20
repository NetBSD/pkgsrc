# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:33 joerg Exp $

BUILDLINK_TREE+=	libspectrum

.if !defined(LIBSPECTRUM_BUILDLINK3_MK)
LIBSPECTRUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspectrum+=		libspectrum>=0.2.2
BUILDLINK_ABI_DEPENDS.libspectrum+=	libspectrum>=0.2.2nb2
BUILDLINK_PKGSRCDIR.libspectrum?=	../../emulators/libspectrum

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.endif # LIBSPECTRUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspectrum
