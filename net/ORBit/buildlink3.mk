# $NetBSD: buildlink3.mk,v 1.1 2004/01/22 12:53:48 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ORBIT_BUILDLINK3_MK:=	${ORBIT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ORBit
.endif

.if !empty(ORBIT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		ORBit
BUILDLINK_DEPENDS.ORBit?=	ORBit>=0.5.15nb5
BUILDLINK_PKGSRCDIR.ORBit?=	../../net/ORBit

.  include "../../devel/gettext-lib/buildlink3.mk"
.  include "../../devel/glib/buildlink3.mk"
.  include "../../security/tcp_wrappers/buildlink3.mk"
.endif # ORBIT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
