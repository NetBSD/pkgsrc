# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 09:12:12 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SJ3_LIB_BUILDLINK3_MK:=	${SJ3_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	sj3-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsj3-lib}
BUILDLINK_PACKAGES+=	sj3-lib

.if !empty(SJ3_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.sj3-lib+=	sj3-lib>=2.0.1.20nb1
BUILDLINK_PKGSRCDIR.sj3-lib?=	../../inputmethod/sj3-lib
.endif	# SJ3_LIB_BUILDLINK3_MK

.include "../../devel/nbitools/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
