# $NetBSD: buildlink3.mk,v 1.11 2021/05/15 11:05:29 nia Exp $

BUILDLINK_TREE+=	fftw

.if !defined(FFTW_BUILDLINK3_MK)
FFTW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fftw+=	fftw>=3.0
BUILDLINK_ABI_DEPENDS.fftw+=	fftw>=3.1nb1
BUILDLINK_PKGSRCDIR.fftw?=	../../math/fftw

pkgbase := fftw
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.fftw:Mmpi}
.include "../../mk/mpi.buildlink3.mk"
.endif

.endif # FFTW_BUILDLINK3_MK

BUILDLINK_TREE+=	-fftw
