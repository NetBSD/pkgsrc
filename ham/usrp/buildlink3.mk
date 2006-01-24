# $NetBSD: buildlink3.mk,v 1.3 2006/01/24 07:32:18 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
USRP_BUILDLINK3_MK:=	${USRP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	usrp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nusrp}
BUILDLINK_PACKAGES+=	usrp

.if !empty(USRP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.usrp+=	usrp>=0.9
BUILDLINK_RECOMMENDED.usrp?=	usrp>=0.9
BUILDLINK_PKGSRCDIR.usrp?=	../../ham/usrp
.endif	# USRP_BUILDLINK3_MK

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
