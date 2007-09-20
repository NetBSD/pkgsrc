# $NetBSD: buildlink3.mk,v 1.3 2007/09/20 21:03:51 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXMLPP_BUILDLINK3_MK:=	${LIBXMLPP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxmlpp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxmlpp}
BUILDLINK_PACKAGES+=	libxmlpp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxmlpp

.if !empty(LIBXMLPP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libxmlpp+=	libxml++>=2.10.0
BUILDLINK_ABI_DEPENDS.libxmlpp+=	libxml++>=2.10.0nb1
BUILDLINK_PKGSRCDIR.libxmlpp?=	../../textproc/libxml++
.endif	# LIBXMLPP_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
