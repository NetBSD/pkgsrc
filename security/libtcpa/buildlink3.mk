# $NetBSD: buildlink3.mk,v 1.3 2004/03/05 19:25:39 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBTCPA_BUILDLINK3_MK:=	${LIBTCPA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtcpa
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibtcpa}
BUILDLINK_PACKAGES+=	libtcpa

.if !empty(LIBTCPA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libtcpa+=	libtcpa>=1.1b
BUILDLINK_PKGSRCDIR.libtcpa?=	../../security/libtcpa
BUILDLINK_DEPMETHOD.libtcpa?=	build

.include "../../security/openssl/buildlink3.mk"

.endif	# LIBTCPA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
