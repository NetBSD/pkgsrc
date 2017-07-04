# $NetBSD: buildlink3.mk,v 1.20 2017/07/04 09:37:26 adam Exp $

BUILDLINK_TREE+=	libspectrum

.if !defined(LIBSPECTRUM_BUILDLINK3_MK)
LIBSPECTRUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspectrum+=	libspectrum>=1.3.5
BUILDLINK_ABI_DEPENDS.libspectrum+=	libspectrum>=1.3.5
BUILDLINK_PKGSRCDIR.libspectrum?=	../../emulators/libspectrum

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.endif # LIBSPECTRUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspectrum
