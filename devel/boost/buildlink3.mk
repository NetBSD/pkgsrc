# $NetBSD: buildlink3.mk,v 1.3 2004/06/06 23:51:36 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BOOST_BUILDLINK3_MK:=	${BOOST_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	boost
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nboost}
BUILDLINK_PACKAGES+=	boost

.if !empty(BOOST_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.boost?=	boost-1.31.* # ABI requires exactly this pattern
BUILDLINK_PKGSRCDIR.boost?=	../../devel/boost
BUILDLINK_CPPFLAGS.boost+=	-I${BUILDLINK_PREFIX.boost}/include/boost-1_31
.endif	# BOOST_BUILDLINK3_MK

.include "../../devel/boost/toolset.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
