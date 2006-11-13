# $NetBSD: buildlink3.mk,v 1.10 2006/11/13 18:01:29 wulf Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
USRP_BUILDLINK3_MK:=	${USRP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	usrp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nusrp}
BUILDLINK_PACKAGES+=	usrp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}usrp

.if ${USRP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.usrp+=	usrp>=3.0.2
BUILDLINK_PKGSRCDIR.usrp?=	../../ham/usrp
.endif	# USRP_BUILDLINK3_MK

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
