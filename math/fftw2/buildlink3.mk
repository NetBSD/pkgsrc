# $NetBSD: buildlink3.mk,v 1.1 2004/02/19 11:11:31 wiz Exp $
#
# This Makefile fragment is included by packages that use fftw2.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FFTW2_BUILDLINK3_MK:=	${FFTW2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fftw2
.endif

.if !empty(FFTW2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			fftw2
BUILDLINK_DEPENDS.fftw2+=		fftw2>=2.1.3
BUILDLINK_PKGSRCDIR.fftw2?=		../../math/fftw2

.endif # FFTW2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
