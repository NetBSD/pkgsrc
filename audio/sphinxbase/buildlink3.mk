# $NetBSD: buildlink3.mk,v 1.3 2022/03/28 10:43:39 tnn Exp $

BUILDLINK_TREE+=	sphinxbase

.if !defined(SPHINXBASE_BUILDLINK3_MK)
SPHINXBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sphinxbase+=	sphinxbase>=0.8
BUILDLINK_ABI_DEPENDS.sphinxbase+=	sphinxbase>=0.8nb8
BUILDLINK_PKGSRCDIR.sphinxbase?=	../../audio/sphinxbase
BUILDLINK_INCDIRS.sphinxbase+=		include/sphinxbase

pkgbase:= sphinxbase
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.sphinxbase:Msamplerate)
.  include "../../audio/libsamplerate/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.sphinxbase:Msndfile)
.  include "../../audio/libsndfile/buildlink3.mk"
.endif
.endif

BUILDLINK_TREE+=	-sphinxbase
