# $NetBSD: buildlink3.mk,v 1.7 2006/02/05 23:11:04 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENSP_BUILDLINK3_MK:=	${OPENSP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	opensp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopensp}
BUILDLINK_PACKAGES+=	opensp

.if !empty(OPENSP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.opensp+=	opensp>=1.5.1
BUILDLINK_RECOMMENDED.opensp+=	opensp>=1.5.1nb3
BUILDLINK_PKGSRCDIR.opensp?=	../../textproc/opensp
.endif	# OPENSP_BUILDLINK3_MK

PTHREAD_OPTS+=          require

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
