# $NetBSD: buildlink3.mk,v 1.2 2008/03/04 15:52:15 shannonjr Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PCSC_LITE_BUILDLINK3_MK:=	${PCSC_LITE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	pcsc-lite
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npcsc-lite}
BUILDLINK_PACKAGES+=	pcsc-lite
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pcsc-lite

.if ${PCSC_LITE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.pcsc-lite+=	pcsc-lite>=1.4.99
BUILDLINK_PKGSRCDIR.pcsc-lite?=	../../security/pcsc-lite
.endif	# PCSC_LITE_BUILDLINK3_MK

.include "../../devel/libusb/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
