# $NetBSD: buildlink3.mk,v 1.6 2004/10/03 00:15:01 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBREP_BUILDLINK3_MK:=	${LIBREP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	librep
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibrep}
BUILDLINK_PACKAGES+=	librep

.if !empty(LIBREP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.librep+=	librep>=0.17
BUILDLINK_RECOMMENDED.librep+=	librep>=0.17nb1
BUILDLINK_PKGSRCDIR.librep?=	../../lang/librep
MAKE_FLAGS+=			rep_LIBTOOL=${LIBTOOL}
.endif	# LIBREP_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
