# $NetBSD: buildlink3.mk,v 1.1 2004/02/22 21:59:22 jmmv Exp $
#
# This Makefile fragment is included by packages that use opensp.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENSP_BUILDLINK3_MK:=	${OPENSP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	opensp
.endif

.if !empty(OPENSP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			opensp
BUILDLINK_DEPENDS.opensp+=		opensp>=1.5nb1
BUILDLINK_PKGSRCDIR.opensp?=		../../textproc/opensp

PTHREAD_OPTS+=          native

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
.  include "../../devel/unproven-pthreads/buildlink3.mk"
.endif

.endif # OPENSP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
