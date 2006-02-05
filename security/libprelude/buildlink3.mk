# $NetBSD: buildlink3.mk,v 1.2 2006/02/05 23:10:44 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBPRELUDE_BUILDLINK3_MK:=	${LIBPRELUDE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libprelude
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibprelude}
BUILDLINK_PACKAGES+=	libprelude

.if !empty(LIBPRELUDE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libprelude+=	libprelude>=0.9.0
BUILDLINK_RECOMMENDED.libprelude?=	libprelude>=0.9.4nb1
BUILDLINK_PKGSRCDIR.libprelude?=	../../security/libprelude
.endif	# LIBPRELUDE_BUILDLINK3_MK

.include "../../security/gnutls/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
