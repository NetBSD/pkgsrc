# $NetBSD: buildlink3.mk,v 1.5 2004/03/18 09:12:13 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ORBIT2_BUILDLINK3_MK:=	${ORBIT2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ORBit2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NORBit2}
BUILDLINK_PACKAGES+=	ORBit2

.if !empty(ORBIT2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ORBit2+=	ORBit2>=2.8.2
BUILDLINK_PKGSRCDIR.ORBit2?=	../../net/ORBit2
.endif	# ORBIT2_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
