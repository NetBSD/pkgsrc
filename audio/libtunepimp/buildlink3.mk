# $NetBSD: buildlink3.mk,v 1.22 2017/08/24 20:02:56 adam Exp $

BUILDLINK_TREE+=	libtunepimp

.if !defined(LIBTUNEPIMP_BUILDLINK3_MK)
LIBTUNEPIMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtunepimp+=	libtunepimp>=0.5.0
BUILDLINK_ABI_DEPENDS.libtunepimp+=	libtunepimp>=0.5.3nb20
BUILDLINK_PKGSRCDIR.libtunepimp?=	../../audio/libtunepimp

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/libofa/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # LIBTUNEPIMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtunepimp
