# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/02/22 01:40:04 schmonz Exp $
#
# This Makefile fragment is included by packages that use libtcpa.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBTCPA_BUILDLINK3_MK:=	${LIBTCPA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtcpa
.endif

.if !empty(LIBTCPA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libtcpa
BUILDLINK_DEPENDS.libtcpa+=		libtcpa>=1.1b
BUILDLINK_PKGSRCDIR.libtcpa?=		../../security/libtcpa

.include "../../security/openssl/buildlink3.mk"

.endif # LIBTCPA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
