# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:10:45 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBPRELUDEDB_BUILDLINK3_MK:=	${LIBPRELUDEDB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libpreludedb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibpreludedb}
BUILDLINK_PACKAGES+=	libpreludedb

.if !empty(LIBPRELUDEDB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libpreludedb+=	libpreludedb>=0.9.3
BUILDLINK_RECOMMENDED.libpreludedb?=	libpreludedb>=0.9.3nb1
BUILDLINK_PKGSRCDIR.libpreludedb?=	../../security/libpreludedb
.endif	# LIBPRELUDEDB_BUILDLINK3_MK

.include "../../security/libprelude/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
