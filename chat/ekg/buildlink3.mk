# $NetBSD: buildlink3.mk,v 1.1 2004/02/19 17:44:17 wiz Exp $
#
# This Makefile fragment is included by packages that use ekg.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EKG_BUILDLINK3_MK:=	${EKG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ekg
.endif

.if !empty(EKG_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		ekg
BUILDLINK_DEPENDS.ekg+=		ekg>=1.1
BUILDLINK_PKGSRCDIR.ekg?=	../../chat/ekg

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif # EKG_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
