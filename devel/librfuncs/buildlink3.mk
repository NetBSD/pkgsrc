# $NetBSD: buildlink3.mk,v 1.3 2004/11/07 10:44:13 shannonjr Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBRFUNCS_BUILDLINK3_MK:=	${LIBRFUNCS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	librfuncs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibrfuncs}
BUILDLINK_PACKAGES+=	librfuncs

.if !empty(LIBRFUNCS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.librfuncs+=	librfuncs>=1.0.4
BUILDLINK_PKGSRCDIR.librfuncs?=	../../devel/librfuncs
.endif	# LIBRFUNCS_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"
BUILDLINK_LDFLAGS.librfuncs+=	-lrfuncs

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
