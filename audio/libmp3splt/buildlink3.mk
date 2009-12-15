# $NetBSD: buildlink3.mk,v 1.5 2009/12/15 21:30:53 joerg Exp $

BUILDLINK_TREE+=	libmp3splt

.if !defined(LIBMP3SPLT_BUILDLINK3_MK)
LIBMP3SPLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmp3splt+=	libmp3splt>=0.5.1
BUILDLINK_ABI_DEPENDS.libmp3splt+=	libmp3splt>=0.5.6nb1
BUILDLINK_PKGSRCDIR.libmp3splt?=	../../audio/libmp3splt
###
### XXX libmad and libvorbis are needed only for headers.
###
BUILDLINK_DEPMETHOD.libmad?=	build
.include "../../audio/libmad/buildlink3.mk"

BUILDLINK_DEPMETHOD.libvorbis?= build
.include "../../audio/libvorbis/buildlink3.mk"

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.endif # LIBMP3SPLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmp3splt
