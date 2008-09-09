# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/09/09 11:50:18 jmcneill Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
UNICAP_BUILDLINK3_MK:=	${UNICAP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	unicap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nunicap}
BUILDLINK_PACKAGES+=	unicap
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}unicap

.if !empty(UNICAP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.unicap+=	unicap>=0.9.1
BUILDLINK_ABI_DEPENDS.unicap+=	unicap>=0.9.1
BUILDLINK_PKGSRCDIR.unicap?=	../../graphics/unicap
.endif	# UNICAP_BUILDLINK3_MK

.include "../../x11/libXv/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
