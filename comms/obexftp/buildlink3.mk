# $NetBSD: buildlink3.mk,v 1.1 2006/11/30 00:07:03 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OBEXFTP_BUILDLINK3_MK:=	${OBEXFTP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	obexftp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nobexftp}
BUILDLINK_PACKAGES+=	obexftp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}obexftp

.if ${OBEXFTP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.obexftp+=	obexftp>=0.20nb1
BUILDLINK_PKGSRCDIR.obexftp?=	../../comms/obexftp
.endif	# OBEXFTP_BUILDLINK3_MK

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
