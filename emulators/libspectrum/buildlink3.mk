# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:11 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSPECTRUM_BUILDLINK3_MK:=	${LIBSPECTRUM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libspectrum
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibspectrum}
BUILDLINK_PACKAGES+=	libspectrum

.if !empty(LIBSPECTRUM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libspectrum+=		libspectrum>=0.2.1
BUILDLINK_PKGSRCDIR.libspectrum?=	../../emulators/libspectrum
.endif	# LIBSPECTRUM_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
