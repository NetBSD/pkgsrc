# $NetBSD: buildlink3.mk,v 1.28 2024/05/06 08:40:28 jperkin Exp $

BUILDLINK_TREE+=	octave

.if !defined(OCTAVE_BUILDLINK3_MK)
OCTAVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.octave+=	octave>=3.0.0
BUILDLINK_ABI_DEPENDS.octave+=	octave>=9.1.0nb2
BUILDLINK_PKGSRCDIR.octave?=	../../math/octave

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := octave
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.octave:Mhdf5}
.  include "../../devel/hdf5/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.octave:Mqhull}
.  include "../../math/qhull/buildlink3.mk"
.endif

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/qrupdate/buildlink3.mk"
.endif # OCTAVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-octave
