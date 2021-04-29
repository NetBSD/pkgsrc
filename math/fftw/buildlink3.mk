# $NetBSD: buildlink3.mk,v 1.9 2021/04/29 23:30:15 thor Exp $

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
