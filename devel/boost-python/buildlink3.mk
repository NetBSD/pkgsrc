# $NetBSD: buildlink3.mk,v 1.15 2009/03/19 17:05:51 cube Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
BOOST_PYTHON_BUILDLINK3_MK:=	${BOOST_PYTHON_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	boost-python
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nboost-python}
BUILDLINK_PACKAGES+=	boost-python
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}boost-python

.if !empty(BOOST_PYTHON_BUILDLINK3_MK:M+)
# Use a dependency pattern that guarantees the proper ABI.
BUILDLINK_API_DEPENDS.boost-python+=	boost-python-1.38.*
BUILDLINK_ABI_DEPENDS.boost-python?=	boost-python>=1.38.*
BUILDLINK_PKGSRCDIR.boost-python?=	../../devel/boost-python
.endif	# BOOST_PYTHON_BUILDLINK3_MK

.include "../../devel/boost-headers/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
