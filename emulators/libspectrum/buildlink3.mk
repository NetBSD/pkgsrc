# $NetBSD: buildlink3.mk,v 1.1 2004/02/25 18:49:36 minskim Exp $
#
# This Makefile fragment is included by packages that use libspectrum.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSPECTRUM_BUILDLINK3_MK:=	${LIBSPECTRUM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libspectrum
.endif

.if !empty(LIBSPECTRUM_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libspectrum
BUILDLINK_DEPENDS.libspectrum+=		libspectrum>=0.2.1
BUILDLINK_PKGSRCDIR.libspectrum?=		../../emulators/libspectrum

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.endif # LIBSPECTRUM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
