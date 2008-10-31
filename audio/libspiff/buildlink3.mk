# $NetBSD: buildlink3.mk,v 1.3 2008/10/31 22:36:28 bjs Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSPIFF_BUILDLINK3_MK:=	${LIBSPIFF_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libspiff
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibspiff}
BUILDLINK_PACKAGES+=	libspiff
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libspiff

.if ${LIBSPIFF_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libspiff+=	libspiff>=1.0.0
BUILDLINK_PKGSRCDIR.libspiff?=	../../audio/libspiff
.endif	# LIBSPIFF_BUILDLINK3_MK

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/uriparser/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
