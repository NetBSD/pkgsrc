# $NetBSD: buildlink3.mk,v 1.1 2004/02/29 18:29:02 wiz Exp $
#
# This Makefile fragment is included by packages that use boost.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BOOST_BUILDLINK3_MK:=	${BOOST_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	boost
.endif

.if !empty(BOOST_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			boost
BUILDLINK_DEPENDS.boost+=		boost>=1.30.2
BUILDLINK_PKGSRCDIR.boost?=		../../devel/boost

.endif # BOOST_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
