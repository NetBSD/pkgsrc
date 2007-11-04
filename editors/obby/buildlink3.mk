# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/11/04 10:06:06 rillig Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OBBY_BUILDLINK3_MK:=	${OBBY_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	obby
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nobby}
BUILDLINK_PACKAGES+=	obby
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}obby

.if ${OBBY_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.obby+=	obby>=0.4.4
BUILDLINK_PKGSRCDIR.obby?=	../../editors/obby
.endif	# OBBY_BUILDLINK3_MK

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../net/net6/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
