# $NetBSD: buildlink3.mk,v 1.4 2004/03/18 09:12:13 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ORBIT_BUILDLINK3_MK:=	${ORBIT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ORBit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NORBit}
BUILDLINK_PACKAGES+=	ORBit

.if !empty(ORBIT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ORBit+=	ORBit>=0.5.15nb5
BUILDLINK_PKGSRCDIR.ORBit?=	../../net/ORBit
.endif	# ORBIT_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
