# $NetBSD: buildlink3.mk,v 1.3 2004/03/05 19:25:40 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBPATHAN_BUILDLINK3_MK:=	${LIBPATHAN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libpathan
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibpathan}
BUILDLINK_PACKAGES+=	libpathan

.if !empty(LIBPATHAN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libpathan+=	libpathan>=1.2.2
BUILDLINK_PKGSRCDIR.libpathan?=	../../textproc/libpathan

.include "../../textproc/xerces-c/buildlink3.mk"

.endif	# LIBPATHAN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
