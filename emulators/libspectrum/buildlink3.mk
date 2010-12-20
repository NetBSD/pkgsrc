# $NetBSD: buildlink3.mk,v 1.12 2010/12/20 20:51:36 adam Exp $

BUILDLINK_TREE+=	libspectrum

.if !defined(LIBSPECTRUM_BUILDLINK3_MK)
LIBSPECTRUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspectrum+=		libspectrum>=0.2.2
BUILDLINK_ABI_DEPENDS.libspectrum+=	libspectrum>=0.2.2nb2
BUILDLINK_PKGSRCDIR.libspectrum?=	../../emulators/libspectrum

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.endif # LIBSPECTRUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspectrum
