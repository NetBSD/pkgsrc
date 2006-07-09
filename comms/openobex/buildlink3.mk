# $NetBSD: buildlink3.mk,v 1.9 2006/07/09 09:27:52 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OPENOBEX_BUILDLINK3_MK:=	${OPENOBEX_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	openobex
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenobex}
BUILDLINK_PACKAGES+=	openobex

.if ${OPENOBEX_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.openobex+=	openobex>=1.3
BUILDLINK_PKGSRCDIR.openobex?=	../../comms/openobex
.endif	# OPENOBEX_BUILDLINK3_MK

.include "../../devel/libusb/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
