# $NetBSD: buildlink3.mk,v 1.6 2004/04/01 18:16:17 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ORBIT2_BUILDLINK3_MK:=	${ORBIT2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ORBit2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NORBit2}
BUILDLINK_PACKAGES+=	ORBit2

.if !empty(ORBIT2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ORBit2+=	ORBit2>=2.10.0
BUILDLINK_PKGSRCDIR.ORBit2?=	../../net/ORBit2
.endif	# ORBIT2_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
