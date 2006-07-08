# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:10:59 jlam Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OCTAVE_CURRENT_BUILDLINK3_MK:=	${OCTAVE_CURRENT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	octave-current
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Noctave-current}
BUILDLINK_PACKAGES+=	octave-current
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}octave-current

.if !empty(OCTAVE_CURRENT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.octave-current+=	octave-current>=2.1.57
BUILDLINK_ABI_DEPENDS.octave-current+=	octave-current>=2.9.4nb1
BUILDLINK_PKGSRCDIR.octave-current?=	../../math/octave-current
.endif	# OCTAVE_CURRENT_BUILDLINK3_MK

.include "../../mk/bsd.prefs.mk"

.if !defined(PKG_OPTIONS.octave:) || !empty(PKG_OPTIONS.octave:Mhdf5)
.include "../../devel/hdf5/buildlink3.mk"
.endif

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
