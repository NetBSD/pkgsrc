# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/04/08 03:03:42 riz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
ZAPTEL_NETBSD_BUILDLINK3_MK:=	${ZAPTEL_NETBSD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	zaptel-netbsd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nzaptel-netbsd}
BUILDLINK_PACKAGES+=	zaptel-netbsd

.if !empty(ZAPTEL_NETBSD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.zaptel-netbsd+=	zaptel-netbsd>=20050314
BUILDLINK_PKGSRCDIR.zaptel-netbsd?=	../../comms/zaptel-netbsd
BUILDLINK_DEPMETHOD.zaptel-netbsd?=	build
.endif	# ZAPTEL_NETBSD_BUILDLINK3_MK

.include "../../wip/newt/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
