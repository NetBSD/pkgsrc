# $NetBSD: buildlink3.mk,v 1.16 2006/07/08 23:10:38 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EKG_BUILDLINK3_MK:=	${EKG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ekg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nekg}
BUILDLINK_PACKAGES+=	ekg
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ekg

.if !empty(EKG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.ekg+=		ekg>=1.6
BUILDLINK_ABI_DEPENDS.ekg?=	ekg>=1.6nb4
BUILDLINK_PKGSRCDIR.ekg?=	../../chat/ekg
.endif	# EKG_BUILDLINK3_MK

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
