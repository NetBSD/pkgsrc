# $NetBSD: buildlink3.mk,v 1.7 2006/04/06 06:21:59 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSPECTRUM_BUILDLINK3_MK:=	${LIBSPECTRUM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libspectrum
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibspectrum}
BUILDLINK_PACKAGES+=	libspectrum

.if !empty(LIBSPECTRUM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libspectrum+=		libspectrum>=0.2.2
BUILDLINK_ABI_DEPENDS.libspectrum+=	libspectrum>=0.2.2nb2
BUILDLINK_PKGSRCDIR.libspectrum?=	../../emulators/libspectrum
.endif	# LIBSPECTRUM_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
