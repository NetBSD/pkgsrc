# $NetBSD: buildlink3.mk,v 1.5 2004/03/26 02:27:52 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBTCPA_BUILDLINK3_MK:=	${LIBTCPA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtcpa
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibtcpa}
BUILDLINK_PACKAGES+=	libtcpa

.if !empty(LIBTCPA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libtcpa+=	libtcpa>=1.1b
BUILDLINK_RECOMMENDED.libtcpa?=	libtcpa>=1.1bnb1
BUILDLINK_PKGSRCDIR.libtcpa?=	../../security/libtcpa
BUILDLINK_DEPMETHOD.libtcpa?=	build
.endif	# LIBTCPA_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
