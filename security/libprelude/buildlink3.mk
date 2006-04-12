# $NetBSD: buildlink3.mk,v 1.6 2006/04/12 10:27:33 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBPRELUDE_BUILDLINK3_MK:=	${LIBPRELUDE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libprelude
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibprelude}
BUILDLINK_PACKAGES+=	libprelude

.if !empty(LIBPRELUDE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libprelude+=	libprelude>=0.9.0
BUILDLINK_ABI_DEPENDS.libprelude?=	libprelude>=0.9.7
BUILDLINK_PKGSRCDIR.libprelude?=	../../security/libprelude
.endif	# LIBPRELUDE_BUILDLINK3_MK

.include "../../security/gnutls/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
